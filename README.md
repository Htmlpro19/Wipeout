# Game Technology Project 1
TODO: Insert project description here.
Link for milestone documentation: https://docs.google.com/document/d/1I8gp3Wp6AIJhgAFdRwjdtINfy37_oDJGJKEYYP11wSk/edit?usp=sharing
## Building the Project
After checking out the project with either
```
git clone git@gitlab.com:daniamir/gametechproject1.git
```
or 
```
git clone https://gitlab.com/daniamir/gametechproject1.git
```
you should find all the necessary files to build the program. First we must build the CPP bindings.<br>
Open your terminal of choice, and navigate to your project directory. Use the following commands to build the bindings:
```
cd godot-cpp
scons platform=<platform> generate_bindings=yes -j4 use_custom_api_file=yes custom_api_file=../api.json
```
where `<platform>` is the operating system you are using, either linux, osx, or windows.<br>
Next use the following commands to build the project:
```
cd ..
scons platform=<platform>
```
where <platform> is once again the operating system you are using.<br>
## Adding Files
For each CPP class you create in the source code, it is important to update `src/gdlibrary.cpp` to include them. First, add an include statement with the header file of the class you wish to include. Then, in the following function, add the following code in this format:
```
extern "C" void GDN_EXPORT godot_nativescript_init(void *handle) {
    godot::Godot::nativescript_init(handle);

    godot::register_class<godot::MY_CUSTOM_CLASS_NAME>();
}
```
You must also create a `gdns` file for each custom class you create in this format, and place it in the `project/bin/` folder:
```
[gd_resource type="NativeScript" load_steps=2 format=2]

[ext_resource path="res://bin/gametechproject1.gdnlib" type="GDNativeLibrary" id=1]

[resource]

resource_name = "MY_HEADER_FILE_NAME"
class_name = "MY_CLASS_NAME"
library = ExtResource( 1 )
```
This file will be the script you attach to any nodes to determine their behavior.
