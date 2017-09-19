#include <string>
#include <fstream>
#include <streambuf>

std::ifstream t("file.txt");
std::string str((std::istreambuf_iterator<char>(t)),
                 std::istreambuf_iterator<char>());
#include <helios/geo/MapData.hpp>

int main(int argc, char** argv)
{
  using namespace blippar::geo;
 
  if(argc < 2)
  {
      std::cout << "Usage:./test_geo  <path_to_json_file> " << std::endl;
      return 1;
  } 
  std::ifstream t(argv[1]);
  EarthPoint ep(37.391808,-122.070826);
  std::string str((std::istreambuf_iterator<char>(t)),
                 std::istreambuf_iterator<char>());
  MapManager mm(str, ep);
  return 0;
}
