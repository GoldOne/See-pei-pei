Memory Management
================

You are to implement and test a dynamic memory management unit that can be initialised to operate on the following allocation schemes: First Fit, Next Fit, Best Fit and Worst Fit. (Next Fit is the same as First Fit except the search is commenced at the last allocated position and wrapped back to the start if the end of the array is reached.)

The following class declaration shows how this can be implemented:
```cpp
typedef unsigned int WORD;
enum Policy{eFirstFit,eNextFit,eBestFit,eWorstFit};
class DMM
{
      public:
            DMM(WORD *Memory, int Words, Policy Type);
            char *New(int Size); // size in bytes
            void Delete(char *Address);
            void GetStats(int &TotalMemory, int &NumCompares);
      private:
      . . .
};
```
Your task is to complete the class implementation so that the memory can be allocated and deallocated through the use of methods `New()` and `Delete()`. You may implement any private member functions and data you consider necessary. Save your work in files `dmm.h` and `dmm.cpp`.

When the above class is created, the constructor is passed the address of the memory to be used by the memory management unit and the number of `WORDS` comprising this memory. The last parameter indicates the allocation scheme used for allocating memory. This memory can be allocated with the new operator and passed to the memory management unit via the class constructor. (The reason for using `unsigned ints` for the memory is so that we can ensure that the data is aligned to 4 byte word boundaries and is efficient for transfers via the data bus

For example, if a user creates an instance of this class using the following:
```cpp
WORD *Buff = new WORD[96];
DMM(Buff, 96, eFirstFit);
```
The following formatting will occur in the allocated memory segment:
![g](http://i8.tietuku.com/9a5aa6128fce537e.png) 

This formatting is needed to keep track of free and allocated memory segments. You will notice that even though the memory segment assigned to the class is 98 elements long, only 96 are usable. This is because 2 elements are used on each segment to represent the header and tailer information (same). This header/tailer information indicates if the segment is free or allocated (i.e. bit 31) and its size (i.e. bits 0..30).

The `New()` method is passed an integer representing the size (in chars) of the memory to be allocated and returns the address of this memory as a `char*`. (Note: a `WORD` is four `chars` in size.) For example, if the user allocates 16 chars (i.e. 4 WORDS) from the above memory, the following formatting will occur.
![g](http://i8.tietuku.com/d83bb659c147b31c.png) 

When the memory becomes fragmented, the `New()` method should search for a free segment in accordance with the scheduling policy set by the constructor. If the free segment is significantly larger than the memory to be allocated then it should be split.

The `Delete()` function receives a pointer to previously allocated memory which is to be freed. When converted to a `(WORD*)` this should point to the first element of the allocated block. Before changing the memory, checks should be performed to see whether or not the block is allocated and whether or not the trailer of the block is actually the same as the header. If any one of these is not true then your program should terminate as you are probably trying to free a block that is not valid. `Delete()` should also look for segments on the left and right of the one being freed and if either, or both, are free they should be merged together into a larger free segment.

To analyse the complexity of our dynamic memory management unit we will count the number of allocations and `WORD` comparisons performed by the `new()` operation over the lifetime of the class object as well as how much memory was allocated. To do this provide extra private members for counting the total number of allocations and WORD comparisons performed when searching for holes and the total memory allocated (i.e. chars). The stats are accessed via the `GetStats()` method.

Once you have completed implementing the class write a driver program named `main.cpp` for testing your memory management unit. Your driver should receive 4 command line arguments: Size, Seed, Max and N, representing the size of the array, the seed for rand(), the max block size (WORDS), and the number of iterations done for each test, respectively. For each algorithm (policy) your driver should do the following:
```cpp
              Construct MMU with Size and policy
              Sd = Seed;
              For i=0; i < N; i++
                   SRand(Sd++)
                   Loop
                        NumChars = ( rand() % Max + 1 ) * 4
                        Addr = Allocate NumChars
                        if Addr == 0 break // memory full
                        List.Add(Addr)
                   SRand(Sd++)
                   M = NumItemsInList() / 2
                   For j=0; j < M; j++
                        Pos = Rand % NumItemsInList()
                        Remove Addr at Pos from list
                        Delete memory at Addr
                   PrintStats()
```

The output from the driver should look like below. (Note: XXXX should be replaced with the appropriate input and performance figures.)
```cpp
Size: XXXXX Seed: XXXXX Mod: XXXXX N: XXXXX

                   Tot Bytes             Ave Cmps Per           Tot Blocks             Ave Cmps Per
                   Allocated            Byte Allocated           Allocated            Block Allocated

FirstFit:             XXXXX                 XXXXX                 XXXXX                  XXXXX
NextFit:              XXXXX                 XXXXX                 XXXXX                  XXXXX
Best_Fit:             XXXXX                 XXXXX                 XXXXX                  XXXXX
WorstFit:             XXXXX                 XXXXX                 XXXXX                  XXXXX
```
Note: If valid arguments are not received by `main()` print an error message and exit.
