# AutoSob

AutoSob is a GUI-based Discord tool that automatically reacts to messages with the :sob: (`:sob:`) emoji in a specified channel, with an optional user ID filter.

It features a simple interface for authentication via user-token and configuring which channel or user to target.

<img width="717" height="277" alt="autosob-preview" src="https://github.com/user-attachments/assets/0bac8f16-f64a-4702-865d-f35bde6162a7" />

> **Status:** early development

## Features
- [x] Slint GUI implementation
- [x] Token authentication
- [x] Channel ID/User ID inputs
- [x] Application layout
- [ ] Message monitoring
- [ ] Automatic :sob: reactions

## Building from Source
### Requirements
- C++ compiler supporting C++20
- [CMake](https://cmake.org/download/)
- [Git](https://git-scm.com/)
> [!NOTE]
> Required dependencies are automatically fetched by CMake during configuration

### Instructions
1. Clone the repository
```
git clone https://github.com/anxrhy/AutoSob.git
cd AutoSob
```
2. Configure the project
```
cmake -S . -B build/
```
3. Compile the application
```
cmake --build build/
```
4. Run the application
```
./build/AutoSob
```

## Project Structure

```
AutoSob/
├── android/
│   ├── .DS_Store
│   ├── build.gradle.kts
│   ├── gradle/
│   │   └── wrapper/
│   │       └── gradle-wrapper.properties
│   ├── gradle.properties
│   ├── settings.gradle.kts
│   └── src/
│       └── main/
│           └── AndroidManifest.xml
├── CMakeLists.txt
├── src/
│   ├── discord.cpp
│   ├── discord.h
│   └── main.cpp
└── ui/
    └── app-window.slint
```

