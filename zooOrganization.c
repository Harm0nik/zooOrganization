#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Cage Cage;
typedef struct Section Section;


struct Cage
{
    char animal[1000 + 2];
};


struct Section
{
    struct Cage * cages;
    int numCages;
};

int main()
{
    int numSections, command, section, cage;
    char animalName[1000 + 2];
    struct Section * allSections;

    // Read in the number of sections
    scanf("%d", &numSections);

    allSections = (Section *) calloc(numSections, sizeof(Section));

	// Set initial cages to NULL and the number of cages to 0 for each section
    for (int i = 0; i < numSections; i++)
    {
        allSections[i].numCages = 0;
        allSections[i].cages = NULL;
    }

    // Handle commands
    while (command != 4) 
    {
        scanf("%d", &command);

        switch(command) 
        {                                   
			// handle assigning cages to sections
            case 1:

                scanf("%d%d", &section, &cage);
                
				// reassigns memory based for a section based on number of cages
                allSections[section-1].cages = realloc(allSections[section-1].cages, sizeof(Cage) * cage);
                allSections[section-1].numCages = cage;

                break;

			// read in animal names to cages in sections
            case 2:

                scanf("%d%d", &section, &cage);

				// check if cage that is inputted is more than what is assigned, ignore command if true
                if (allSections[section-1].numCages < cage)
                {
                    continue;
                }

                if (section > numSections) 
                {
                    continue;
                }

				// read name directly into cage animal variable
                scanf("%s", allSections[section-1].cages[cage-1].animal);

                break;

			// print out animal name that is in the cage
            case 3:

                scanf("%d%d", &section, &cage);

				// check if string is empty, print animal not found if true, start new command
                if (strlen(allSections[section-1].cages[cage-1].animal) == 0)
                {
                    printf("No animal found.\n");
                    continue;
                }

				// print the animal name
                printf("%s\n", allSections[section-1].cages[cage-1].animal);

                break;
                
        }
    }

    // Clean up remaining memory
	// free all the cages in each section
    for(int i = 0; i < numSections; i++)
    {
        free(allSections[i].cages);
    }

	// free the sections themselves
    free(allSections);

    return 0;
}