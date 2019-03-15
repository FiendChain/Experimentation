import serial
import argparse
import time
import threading

class SerialMonitor:
    def __init__(self, *args, **kwargs):
        self.ser = serial.Serial(*args, **kwargs)
        self.is_running = True
        self.output_history = []
        self.read_thread = threading.Thread(target=self.read_output)
        self.send_thread = threading.Thread(target=self.send_input)

    def run(self):
        self.send_thread.start()
        self.read_thread.start()

        self.send_thread.join()
        self.read_thread.join()

    def read_output(self):
        carriage_return = True

        while self.is_running:
            total_bytes = self.ser.in_waiting
            if total_bytes > 0:
                data = self.ser.read(total_bytes)
                string = data.decode('ascii')
                self.output_history.append(string)
                # if reading string for first time, remove the carriage
                if carriage_return:
                    print('\r', end='')
                    carriage_return = False
                # if ended with newline, entire stream was read properly
                # otherwise, dont end with the >> console string
                if string[-1] == '\n':
                    print(string, flush=True, end='>>')
                    carriage_return = True # since we printed >>, do carriage return if more lines
                else:
                    print(string, flush=True, end='')
            else:
                carriage_return = True

            time.sleep(0.05)
    
    def stop(self):
        self.is_running = False

    def send_input(self):
        try:
            while self.is_running:
                line = input('>>')
                if not line:
                    continue
                elif line == '!q':
                    self.stop()
                    return
                else:
                    byte_stream = bytes(line, 'ascii')
                    total_bytes = self.ser.write(byte_stream)
        except KeyboardInterrupt:
            print('Exitting')
        except Exception as ex:
            print('Unknown exception')
            print(ex)

        self.stop()

def main():
    parser = argparse.ArgumentParser(description='Open serial monitor')
    parser.add_argument('--port', default='COM5')
    parser.add_argument('--baud_rate', type=int, default=9600)

    args = parser.parse_args()

    try:
        ser = SerialMonitor(args.port, args.baud_rate)
        ser.run()
    except FileNotFoundError:
        print('{} does not exist!'.format(args.port))

if __name__ == '__main__':
    main()
