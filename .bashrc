export CCFLAGS="-Wall -Wextra -pedantic -g -Weffc++"

	alias g++='echo "Use w++17 (warnings) or e++17 (warnings are errors)."'

	alias g++17="\g++ -std=c++17 -g"
	alias w++17="\g++ -std=c++17 \${CCFLAGS}"
	alias e++17="\g++ -std=c++17 \${CCFLAGS} -Werror"
