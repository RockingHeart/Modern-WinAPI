import std;
import winapi;

int main() {
	handle_module* module = winapi::load_module<char>("ntdll.dll");
	std::cout << module << '\n';
	std::cout <<  winapi::module_func<int>(module, "LdrLoadDll")();
}