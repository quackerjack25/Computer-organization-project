#include <iostream>
using namespace std;

#define SZ 10

struct A {
   char aBuffer[SZ];
   int  Size;
};
void Snooper(struct A yourA) 
{

	
   char* p = (char*) &yourA;
   printf("Snooper: address of yourA:         %d\n", p);
   printf("Snooper: address of yourA.aBuffer: %d\n",
                       &yourA.aBuffer);
   printf("Snooper: address of yourA.Size:    %d\n", &yourA.Size);
	
   int sizeofA = sizeof(struct A);

   printf("Snooper: number of bytes in yourA: %d\n", sizeofA);

   for (int idx = 0; idx < sizeofA; idx++, p++) {

      printf("Snooper:  byte %2d of yourA at address %d is: %d\n",
                        idx, p, *p);
   }
}
int main() {
	A myStruct;
	
	for (int i=0; i<SZ; i++)
		myStruct.aBuffer[i] = i+97;
	myStruct.Size = SZ;
	Snooper(myStruct);
	return 0;
}




