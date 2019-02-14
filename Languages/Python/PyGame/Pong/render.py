from Pong import Pong

def main():
    game = Pong()
    while game.isOpen:
        game.run()
        
        
if __name__ == "__main__":
    main()

