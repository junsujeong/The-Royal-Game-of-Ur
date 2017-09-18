#include "../gameUr/RollDice.h"
#include <assert.h>

const int TEST_RUNS = 160000;
const double UPPER_ERROR = 1.05;
const double LOWER_ERROR = 0.95;
const float ZERO_FOUR_PROB = 0.0625;
const float ONE_THREE_PROB = 0.25;
const float TWO_PROB = 0.375;

int main()
{
   //Rolls TEST_RUNS number of times to create smooth/accurate probabilty distribution.
   RollDice * rd = new RollDice();
   int num0, num1, num2, num3, num4, crt ;
   num0 = num1 = num2 = num3 = num4 = crt = 0;
   for (int i = 0; i < TEST_RUNS; i++)
   {
      rd->rollAllDice();
      crt = rd->getTotalValue();
      if (crt == 0)
         num0++;
      else if (crt == 1)
         num1++;
      else if (crt == 2)
         num2++;
      else if (crt == 3)
         num3++;
      else if (crt == 4)
         num4++;
   }

   //This portion calculates and prints whether the 
   //probabilities of each roll is accurate.
   assert(num0 < (TEST_RUNS * ZERO_FOUR_PROB * UPPER_ERROR) &&
      num0 >(TEST_RUNS * ZERO_FOUR_PROB * LOWER_ERROR));
   assert(num1 < (TEST_RUNS * ONE_THREE_PROB * UPPER_ERROR) &&
      num1 >(TEST_RUNS * ONE_THREE_PROB * LOWER_ERROR));
   assert(num2 < (TEST_RUNS * TWO_PROB * UPPER_ERROR) &&
      num2 >(TEST_RUNS * TWO_PROB * LOWER_ERROR));
   assert(num3 < (TEST_RUNS * ONE_THREE_PROB * UPPER_ERROR) &&
      num3 >(TEST_RUNS * ONE_THREE_PROB * LOWER_ERROR));
   assert(num4 < (TEST_RUNS * ZERO_FOUR_PROB * UPPER_ERROR) &&
      num4 >(TEST_RUNS * ZERO_FOUR_PROB * LOWER_ERROR));
   assert(rd->GetString() != "");
   return 0;
}