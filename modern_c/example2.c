#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>


struct Character {
  char *name;
  int age;
  int power;
  char *race;
  int mana;
  int luck;
  char *location;
  char *guild;
};

struct Character *Character_create(char *name, int age, int power, char *race, int mana, int luck, char *location, char *guild)
{
  struct Character *who = malloc(sizeof(struct Character));
  assert(who != NULL);

  who->name = strdup(name);
  who->age = age;
  who->power = power;
  who->race = strdup(race);
  who->mana = mana;
  who->luck = luck;
  who->location = strdup(location);
  who->guild = strdup(guild);

  return who;
}

void Character_destroy(struct Character *who)
{
  assert(who != NULL);

  free(who->name);
  free(who->race);
  free(who->location);
  free(who->guild);
  free(who);

}

void Character_print(struct Character *who)
{
  printf("Name: %s\n, \tAge: %d\n, \tPower: %d\n, \tRace: %s\n, \tMana: %d\n, \tLocation: %s\n, \tGuild: %s\n", who->name, who->age, who->power, who->race, who->mana, who->location, who->guild);
}


int main (int argc, char *argv[])
{
  struct Character *ryan = Character_create("Ryan Odegard", 29, 99, "High Elf", 60, 100, "West Chester", "Dark Brotherhood");
  printf("ryan is at memory location %p:\n", ryan);
  Character_print(ryan);

  Character_destroy(ryan);

  return 0;
}
