Here are instructions on how to contribute:

* First read the README.md to understand what is the project.
* There is a development ROADMAP in [GitHub issue #1](https://github.com/PedroHLC/niemeyer/issues/1)
* Discuss with [the developer](https://t.me/pedrohlc) what and how things can be done.
* Try to keep it KISS: If it can be done simply, keep it simple. Also, do not add unnecessary dependencies.
* For C++ use `clang-format -i --style=LLVM src/{,lib/}*` to auto-format.
* For QML keep the code readable.
* Do not add unnecessary files to your commits.
* Please use reviewable.io to respond to PR's reviews.
* When using translation strings on code, please run `lupdate -verbose -pro niemeyer.pro` to generate the translations source on `lang` folder.

Others suggestions:
* To understand the code, start with `src/main.cpp` and `qml/MainContainer.qml`.

If you have any doubts, you may contact me at GitHub, email (root at pedrohlc dot com), Telegram (@pedrohlc) or Discord (PedroHLC#9217).
