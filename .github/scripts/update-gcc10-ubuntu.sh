#!/bin/bash
currentver="$(gcc -dumpversion)"
requiredver="10.0.0"
 if [ "$(printf '%s\n' "$requiredver" "$currentver" | sort -V | head -n1)" = "$requiredver" ]; then 
      echo "$(tput bold)$(tput setaf 2)Greater than or equal to ${requiredver}$(tput sgr 0)"
      echo
      echo "$(tput bold)$(tput setaf 2)Done!$(tput sgr 0)"
 else
      echo "$(tput bold)$(tput setaf 1)Current gcc version is less than ${requiredver}$(tput sgr 0)"
      echo
      echo "$(tput bold)$(tput setaf 1)Bumping GCC version to 10$(tput sgr 0)"
      echo
      echo
      echo "Moving to current $HOME directory"
      cd ~
      echo
      echo
      echo "$(tput setaf 4)Installing GCC-10 and g++-10$(tput sgr 0)"
      sudo apt install gcc-10 g++-10 -y
      echo
      echo
      echo "$(tput setaf 4)Updating alternatives$(tput sgr 0)"
      sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-10 100 --slave /usr/bin/g++ g++ /usr/bin/g++-10 --slave /usr/bin/gcov gcov /usr/bin/gcov-10
      
      FILE_GCC9=/usr/bin/gcc-9
      if [ -f "$FILE_GCC9" ]; then
            echo "$FILE_GCC9 exists."
            sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-9 90 --slave /usr/bin/g++ g++ /usr/bin/g++-9 --slave /usr/bin/gcov gcov /usr/bin/gcov-9
      else
            echo "Looks like gcc-9 is not installed skipping ..."
      fi
      echo
      echo
      echo "$(tput setaf 4)Installing GNU Arm Embedded Toolchain:$(tput sgr 0)"
      echo
      echo "$(tput setaf 4)Removing old versions first$(tput sgr 0)"
      sudo apt remove gcc-arm-none-eabi
      echo
      echo
      echo "$(tput setaf 4)Fetching Toolchain v10$(tput sgr 0)"

      wget https://developer.arm.com/-/media/Files/downloads/gnu-rm/10-2020q4/gcc-arm-none-eabi-10-2020-q4-major-x86_64-linux.tar.bz2
      echo
      echo
      FILE_GCC_ARM=gcc-arm-none-eabi-10-2020-q4-major-x86_64-linux.tar.bz2
      if [ -f "$FILE_GCC_ARM" ]; then
            echo "$FILE_GCC_ARM Exists. Decompressing..."
            sudo tar xjf ./gcc-arm-none-eabi-10-2020-q4-major-x86_64-linux.tar.bz2 -C /usr/share/
            echo
            echo
            echo "Done."
      fi
      echo
      echo
      echo "$(tput setaf 4)Creating necessary symlinks:$(tput sgr 0)"
      sudo ln -sf /usr/share/gcc-arm-none-eabi-10-2020-q4-major/bin/arm-none-eabi-gcc /usr/bin/arm-none-eabi-gcc
      echo "/usr/bin/arm-none-eabi-gcc ... Done"
      sudo ln -sf /usr/share/gcc-arm-none-eabi-10-2020-q4-major/bin/arm-none-eabi-g++ /usr/bin/arm-none-eabi-g++
      echo "/usr/bin/arm-none-eabi-g++ ... Done"
      sudo ln -sf /usr/share/gcc-arm-none-eabi-10-2020-q4-major/bin/arm-none-eabi-gdb /usr/bin/arm-none-eabi-gdb
      echo "/usr/bin/arm-none-eabi-gdb ... Done"
      sudo ln -sf /usr/share/gcc-arm-none-eabi-10-2020-q4-major/bin/arm-none-eabi-size /usr/bin/arm-none-eabi-size
      echo "/usr/bin/arm-none-eabi-size ... Done"
      echo
      echo
      echo "$(tput bold)$(tput setaf 2)Done!$(tput sgr 0)"
      echo "Current gcc version is: $(gcc -dumpversion)"
      echo
      echo
 fi
