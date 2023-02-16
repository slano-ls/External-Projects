
#include <stdio.h>

int main()           

{
    int width = 0, height = 0, b = 0, a = 0;
    int particlewidth=0, particleheight=0, b1=0, a1=0;
    printf("Enter what you want the length and width of the larger box to be (sep. by <ENTER>)");
    scanf("%d", &width);
    getchar();
    scanf("%d", &height);

printf("\n\n");

    printf("Enter what you want the length and width of the smaller box to be (sep. by <ENTER>)");
    scanf("%d", &particlewidth);
    getchar();
    scanf("%d", &particleheight);

    int movementinitial=0, movementfinal=5, movementchecker=0,x=0;
    while(movementinitial <= movementfinal){
        for (a = 0; a != height; a++) {
                for (b = 0; b != width; b++ ) {

                        if ((a == 0) || (a == height-1) || (b == width-1) || (b == 0)){  // put all * printing condition in one place
                                printf("*");
                        }
                        else
                                printf(" ");
                }
                        printf("\n");
        }
        movementchecker=x;
        while (movementchecker<movementfinal){
            printf("\n");
            movementchecker++;
        }

        // Particle Generation
        for (a1 = 0; a1 != particleheight; a1++) {
                for (b1 = 0; b1 != particlewidth; b1++ ) {
                    if((a1 == 0) || (a1 == particleheight-1) || (b1 == particlewidth-1) || (b1 == 0)){  // put all * printing condition in one place
                                printf("*");
                        }
                        else
                                printf(" ");
                }
                        printf("\n");
        }

        x++;
        movementinitial++;
        printf("\n\n\n\n");
        }
    if (particleheight<height &&particlewidth<width && movementinitial==movementfinal){
        printf("Your object is able to fit with (%d) width remaining and (%d) height remaining", width-particlewidth, height-particleheight);
    }
}
