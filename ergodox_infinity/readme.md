* run the following to get the <SERIAL> number:
  * dfu-util -l




  ## General

  This layout was designed for work in dual environments (Mac/Windows) with Mac being the primary. The escape key has been modified to toggle Windows mode on or off, which updates the modifiers.

  The utility layer is built to include media keys and make certain symbols easier to reach. It also contains macros.

  ## SET UP GUIDE

  * Nav to qmk root

  * run:
    * make ergodox_infinity:keymapname

    _. make ergodox_infinity:experiments_with_code ._

  * enter flash mode on keyboard

  * run the following to get the <SERIAL> number:
    * dfu-util -l

  * run:
      <!-- * dfu-util -S <SERIAL> -D whitefox_experiments_with_code.bin -->
      * sudo make ergodox_infinity:keymapname:dfu-util

      _. sudo make ergodox_infinity:experiments_with_code:dfu-util ._


    * run:
      * make ergodox_infinity:keymapname MASTER=right

      _. make ergodox_infinity:experiments_with_code MASTER=right ._

  * Install the firmware with
    - sudo make ergodox_infinity:keymapname:dfu-util MASTER=right

    _. sudo make ergodox_infinity:experiments_with_code:dfu-util MASTER=right ._
