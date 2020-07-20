// Basic input out Functions
#include <iostream>
// File I/O operations
#include <fstream>
// Track time durations
#include <chrono>

int main(int argc, char const *argv[])
{
    // Test line of 1000 characters
    std::string line = "403rs8VmJmEzcoxJFi5ZLz74l7Y0dICFemS55ks2NNCfAr6wPOS0RCK44rnTOWSDJ97Q86z0JuhU0Bt0yIwOQH8qTRiFemB80VM6tDrh973E5NwgEoJGnDl6ORAs8bRFeiLdLMm25y92anHPxG6iySCyIijHoCAoHwc8jb4wcWVjz6EjQoi0gHCqTtLMtFplGbeGdCjQ1DBtFyqoWpVEX95woEjBwJKVBa8hqWkb1sg93mT37halxJ86FPJxjtkfx94hCvgbTTeziWhbhOJyCAiWQmzThAf3XZWGz9V7JRNXtyc5SljwPWNDeUNE0XM3L600MY7fnQ4OARHc8QCWxh8OXt63KiCEEaUUmX6DawJm5xfw6UTqBXe55ykBqPSufkHjy90TKMnaPBstAtqEZUnYv9ohgHKuCHHYWB5HZFZhRvCxfqHIspTSVVwTonvQtWmMHo0QcVoNXCwfXWPYbdIKFtV4R7ExFw1KZoEhAqsqRloEDpr5J58oG0ynHNGr1iAk2yTvZwNDcfXZuTXXoEtylxyudsTftQeAH8s3Flqb1FzFnv0Y5uI1rB2ghEiUf6r6rfCCSaU9MYBdJ4SiLaN3secIxob8UIrc15kBRrEh7V0SzJ9S1NpaFUV69Qf2lGPNvhD4R7pzX9NK2IhGWLIx4K7EfdoTu5Z12WJYwdFcebnHPWDo1vShymc2w4z17XkRL1dMHcJIbTKBqCMTHRCT6l5ts9DPHcQyTLWLZreB2xRqFQtGiDxnEZv8uaJuTnbWIa70sE2D6wN3yicC3MUBGZF4nfChSkT1VgnTNsfmWo7Oo6KkDM1TXr2G5hqxhm0cqVgCt5sM1wq01zZQnSTodzLrTVoVpp0y3E5xr54k5okHM7nNtMpQ7rQbjIIrZOUHJ8Hsrw05xrm3xrGrX5RmGqXtYgIa0HGM0NQaKWSOyViTbRML8991IwkIN3Dewop7XTcuZAUBUhcClZu3vpqac6lZPFifrT4Nloi";
    // File to store time taken to read lines
    std::fstream timefile("timedur1.txt");

    for (long i = 0; i < 100; i++)
    {
        // File to be read by the script increments by 1000 lines
        std::fstream testfile("testfile1.txt", std::ios::app);
        for (size_t j = 0; j < 1000; j++)
        {
            testfile << line << std::endl;
        }
        testfile.close();

        // Routine to find running time in microsecond
        auto start = std::chrono::high_resolution_clock::now();
        system("./test.sh testfile1.txt");
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

        timefile << (i + 1) * 1000 << " " << duration.count() << std::endl;
    }
    timefile.close();
    return 0;
}
