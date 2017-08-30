upload:
	platformio run -t upload

compile:
	platformio run

monitor:
	 while true; do if ! [[ -n "`lsof /dev/arduino-vec-data`" ]] ; then platformio device monitor; sleep 1; fi done
