#include "GameState.h"

using namespace std;

void saveState(const GameState& state, const std::string& filename)
{
    std::ofstream outFile(filename, std::ios::binary);
    if (outFile.is_open())
    {
        outFile.write(reinterpret_cast<const char*>(&state), sizeof(GameState));
        outFile.close();
    }
    else
    {
        std::cerr << "Lỗi: Không thể mở file để lưu." << std::endl;
    }
}

bool loadState(GameState& state, const std::string& filename)
{
    std::ifstream inFile(filename, std::ios::binary);
    if (inFile.is_open())
    {
        inFile.read(reinterpret_cast<char*>(&state), sizeof(GameState));
        inFile.close();
        return true;
    }
    else
    {
        std::cout << "Lỗi: Không thể mở file để tải." << std::endl;
        return false;
    }
}
