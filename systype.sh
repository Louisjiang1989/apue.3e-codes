# Determine the type of *ix operating system that we're running on, and echo an appropriates value.
# This scripts is intended to be used in Makefiles

case `uname -s` in 
"FreeBSD")
    PLATFORM="freebsd"
    ;;                       #Teminator
"Linux")
    PLATFORM="linux"
    ;;
"Darwin")
    PLATFORM="macos"
    ;;
"SunOS")
    PLATFORM="solaris"
    ;;
*)
    echo "Unknown platform" >&2
    exit 1
esac                                 #end of case
echo $PLATFORM
exit 0
