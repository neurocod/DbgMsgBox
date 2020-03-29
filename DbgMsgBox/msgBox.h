#pragma once

#if defined(WIN32) || defined(Q_OS_WIN)
//in your Windows app launch with:
void msgBox(const std::string& s) {
	std::vector<CHAR> vec;
	for (auto c : s)
		vec.push_back(c);
	vec.push_back(0);

	STARTUPINFOA info;
	ZeroMemory(&info, sizeof(info));
	info.cb = sizeof(info);

	PROCESS_INFORMATION processInfo = {};
	ZeroMemory(&processInfo, sizeof(processInfo));

	BOOL ok = CreateProcessA(R"(D:\dev\DbgMsgBox\x64\Debug\DbgMsgBox.exe)", vec.data(), 0, 0, 0, 0, 0, 0, &info, &processInfo);
	if (ok) {
		WaitForSingleObject(processInfo.hProcess, INFINITE);
		CloseHandle(processInfo.hProcess);
		CloseHandle(processInfo.hThread);
	}
}
#else
//in linux/macos: TODO
void msgBox(const std::string& s) {
	exec(...);
}
#endif