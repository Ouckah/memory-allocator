#include <iostream>
#include <array>
#include <stdexcept>

#define BUFFER_SIZE 32

struct FixedBufferAllocator
{
    std::array<int, BUFFER_SIZE> buffer; // fixed amount of space / memory
    int end_idx;                         // indicator of how much memory is allocated

    int *allocate(int size)
    {
        // invalid size
        if (size <= 0)
        {
            throw std::invalid_argument("Size must be positive.");
        }

        int new_idx = end_idx + size;

        // out of memory
        if (new_idx > buffer.size())
        {
            std::runtime_error("OutOfMemory");
        }

        int *res = &buffer[end_idx]; // get the address of the allocated memory
        end_idx = new_idx;           // move pointer to end of newly allocated block
        return res;                  // return address of newly allocated memory
    }
};