/*
 * random.h
 *
 * ISAAC random number generator by Bob Jenkins.
 *
 * Portable Windows Library
 *
 * Copyright (c) 1993-2000 Equivalence Pty. Ltd.
 *
 * The contents of this file are subject to the Mozilla Public License
 * Version 1.0 (the "License"); you may not use this file except in
 * compliance with the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS"
 * basis, WITHOUT WARRANTY OF ANY KIND, either express or implied. See
 * the License for the specific language governing rights and limitations
 * under the License.
 *
 * The Original Code is Portable Windows Library.
 *
 * The Initial Developer of the Original Code is Equivalence Pty. Ltd.
 *
 * Contributor(s): ______________________________________.
 *
 * $Revision: 21788 $
 * $Author: rjongbloed $
 * $Date: 2008-12-12 05:42:13 +0000 (Fri, 12 Dec 2008) $
 */

#ifndef PTLIB_RANDOM_H
#define PTLIB_RANDOM_H


#ifdef P_USE_PRAGMA
#pragma interface
#endif


/**Mersenne Twister random number generator.
   An application would create a static instance of this class, and then use
   if to generate a sequence of psuedo-random numbers.

   Usually an application would simply use PRandom::Number() but if
   performance is an issue then it could also create a static local variable
   such as:
        {
          static PRandom rand;
          for (i = 0; i < 10000; i++)
             array[i] = rand;
        }

    This method is not thread safe, so it is the applications responsibility
    to assure that its calls are single threaded.
  */
class PRandom
{
  public:
    /**Construct the random number generator.
       This version will seed the random number generator with a value based
       on the system time as returned by time() and clock().
      */
    PRandom();

    /**Construct the random number generator.
       This version allows the application to choose the seed, thus letting it
       get the same sequence of values on each run. Useful for debugging.
      */
    PRandom(
      DWORD seed    ///< New seed value, must not be zero
    );

    /**Set the seed for the random number generator.
      */
    void SetSeed(
      DWORD seed    ///< New seed value, must not be zero
    );

    /**Get the next psuedo-random number in sequence.
       This generates one pseudorandom unsigned integer (32bit) which is
       uniformly distributed among 0 to 2^32-1 for each call.
      */
    unsigned Generate();

    /**Get the next psuedo-random number in sequence.
       This generates one pseudorandom unsigned integer from 0 to maximum.
       Uses the Generate() function and scales accordingly.
      */
    unsigned Generate(unsigned maximum);

    /**Get the next psuedo-random number in sequence.
       This generates one pseudorandom unsigned integer from minimum to maximum.
       Uses the Generate() function and scales and shifts accordingly.
      */
    unsigned Generate(unsigned minimum, unsigned maximum);

    /**Get the next psuedo-random number in sequence.
       This generates one pseudorandom unsigned integer which is
       uniformly distributed among 0 to maximum for each call. Uses
       Generate()
      */
    inline operator unsigned() { return Generate(); }


    /**Get the next psuedo-random number in sequence.
       This utilises a single system wide thread safe PRandom variable. All
       threads etc will share the same psuedo-random sequence.
      */
    static unsigned Number();

    /** Get a random number between zero and maximum
    */
    static unsigned Number(unsigned maximum);

    /** Get a random number between minimum and maximum
    */
    static unsigned Number(unsigned minimum, unsigned maximum);

    /** Get a random set of bits.
    */
    static PBYTEArray Octets(PINDEX size);
    static void Octets(PBYTEArray & octets, PINDEX size = 0);
    static void Octets(BYTE *  octets, PINDEX size);

  protected:
    enum {
      RandBits = 8, ///< I recommend 8 for crypto, 4 for simulations
      RandSize = 1<<RandBits
    };

    DWORD randcnt;
    DWORD randrsl[RandSize];
    DWORD randmem[RandSize];
    DWORD randa;
    DWORD randb;
    DWORD randc;
};


#endif  // PTLIB_RANDOM_H


// End Of File ///////////////////////////////////////////////////////////////
