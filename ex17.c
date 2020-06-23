#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_DATA 512
#define MAX_ROWS 100

struct Address {
	int id;
	int set;
	char name[MAX_DATA];
	char email[MAX_DATA];
};

struct Database {
	struct Address rows[MAX_ROWS];
};

struct Connection {
	FILE *file;
	struct Database *db;
};

void die(const char *message)
{
	if (errno){
		perror(message);
	} else {
		printf("ERROR: %s\n", message);
	}

	exit(1);
}

void Address_print(struct Address *addr)
{
	printf("%d %s %s\n", addr->id, addr->name, addr->email );
}

void Database_load(struct Connection *conn)
{
	int rc = fread(conn->db, sizeof(struct Database), 1, conn->file);
	if (rc != 1)
		die("Failed to load database.");
}

struct Connection *Database_open(const char *filename, char mode)
{
	struct Connection *conn = malloc(sizeof(struct Connection));
	if (!conn)
		die("Memory error");

	conn->db = malloc(sizeof(struct Database));
	if (!conn->db)
		die("Memory error");

	if (mode == 'c'){
		conn->file = fopen(filename, "w");
	} else {
		conn->file = fopen(filename, "r+");

		if (conn->file){
			Database_load(conn);
		}
	}

	if (!conn->file)
		die("Failed to open the file");

	return conn;

}

void Database_close(struct Connection *conn)
{
	if (conn) {
		if (conn->file)
			fclose(conn->file);
		if (conn->db)
			free(conn->db);
		free(conn);
	}
}



int main(int argc, char *argv[])
{
	if (argc < 3)
		die("USAGE: ex17 <dbfile> <action> [action params]");

	char *filename = argv[1];
	char action = argv[2][0];
	struct Connection *conn = Database_open(filename, action);
	int id = 0;

	if (argc > 3) id = atoi(argv[3]);
	if (id >= MAX_ROWS) die("There's not that many records.");

	switch (action) {
		case 'c':
			Database_create(conn);
			Database_write(conn);
			break;

		case 'g':
			if (argc != 4)
				die("Need an id to get");

			Database_get(conn, id);
			break;

		case 's':
			if (argc != 6)
				die("Need id, name, email to set");

			Database_set(conn, id, argv[4], argv[5]);
			Database_write(conn);
			break;

		case 'd':
			if (argc != 4)
				die("Need id to delete");

			Database_delete(conn, id);
			Database_write(conn);
			break;

		case 'l':
			Database_list(conn);
			break;
		default:
			die("Invalid action: c=create, g=get, s=set, d=del, l=list");
	}

	Database_close(conn);

	return 0;
}




//everytime you call malloc HEAP, everything else STACK
//making a structure with malloc = HEAP