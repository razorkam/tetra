# Tetra
Tetra is a text translation plugin for Terminator terminal emulator, which uses Google Translate undocumented API.
## Installation
To install plugin properly, you need CMake build system (and, of course, Terminator) installed.
Process is quite simple:
* Run _cmake CMakeLists.txt_
* After makefile was successfully generated,
  run _make install_tetra_. This command will copy tetra's scripts to Terminator's default plugin directory
  (i.e, _~/.config/terminator/plugins_)
## Usage
For translate some word, or phrase, or maybe a big part of text
you should select it by mouse and rightclick to popup a standart context menu.
Next, choose a menu item named _Translate **{your text}**_ and wait for submenu's activation which shows you
translated version of text.
## Languages
By now, selection of source and target languages for translation is in development.
Despite the fact there are some code snippets related to this feature, it doesn't work properly yet, so disabled.
Languages can be correctly changed just by hardcoding _py_translator_ module, currently.
## C++ translation module
There is _translator_ directory which contains some C++/Boost related stuff wrapping the same
translation API as _py_translator_ module (i.e. Boost::Asio HTTP client and Boost::Python
interface to python plugin script. It wasn't invention of the wheel, just
my experiments with Boost. If for some reasons you want to use it - feel free to run
_make tetra_translator_ (need Boost installed) to compile it and link to shared library.
But be careful: there are no methods to call it from plugin's script for now.



