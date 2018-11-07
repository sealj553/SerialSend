# SerialSend
Pipe data from the shell to a serial port

Simple utility I made because there wasn't an easy way to do this.

Example usage:
```shell
cat file_of_data | ./serial /dev/ttyUSB0 115200
echo "hello world" | ./serial /dev/ttyUSB0 115200
```

TODO:
* Make a switch to also print output to stdout
