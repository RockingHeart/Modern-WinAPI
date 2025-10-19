export module winapi:loader;

export struct handle_module {
	int unuse;
};

export namespace winapi {
	template <typename Type>
	constexpr handle_module* load_module(const Type*) noexcept = delete;

	template <class ReturnType, class... ArgsType>
	constexpr auto module_func(handle_module*, const char*);
}

extern "C" {
	__declspec(dllimport) handle_module* LoadLibraryA(const char*    ModuleName);
	__declspec(dllimport) handle_module* LoadLibraryW(const wchar_t* ModuleName);
}

template <>
handle_module* winapi::load_module<char>(const char* ModuleName) noexcept {
	return LoadLibraryA(ModuleName);
}

template <>
handle_module* winapi::load_module<wchar_t>(const wchar_t* ModuleName) noexcept {
	return LoadLibraryW(ModuleName);
}

extern "C" {
	__declspec(dllimport) void* GetProcAddress(handle_module* Module, const char* Name);
}

template <class ReturnType, class... ArgsType>
constexpr auto winapi::module_func(handle_module* module, const char* func_name) {
	using fun_t = ReturnType(*)(ArgsType...);
	return reinterpret_cast<fun_t>(GetProcAddress(module, func_name));
}