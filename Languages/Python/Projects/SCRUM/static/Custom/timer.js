var Timer = new(function() {
    var timers = [];

    function init() {
        $(".timer").each((index, timer) => {
            timers.push(new Timer(timer));
        });
    }

    class Timer {
        constructor(selector) {
            this.createElement(selector);
            var speed = $(selector).attr('speed');
            if(!speed) speed = 1.0;
            this.speed = speed;
            this.init();
            
        }

        createElement(selector) {
            this.container = $(selector);
            this.timer = this.container.find(".display");
            this.text = this.timer.find("span");
        }

        init() {
            this.running = false;
            this.time = [
                {"value": 0, "max": 24, "prefix": "h"},
                {"value": 0, "max": 60, "prefix": "m"},
                {"value": 0, "max": 60, "prefix": "s"}
            ];
            this.timer.click(() => {
                this.toggle();
            });

            this.updateText();
        }

        toggle() {
            if(!this.running) this.start();
            else              this.pause();
            this.timer.toggleClass("btn-outline-primary");
            this.timer.toggleClass("btn-outline-success");
        }

        start() {
            this.running = true;
            this.updateText();
            this.intervalID = setInterval(increment.bind(this), 1000/this.speed);
            function increment() {
                if(this.running) {
                    this.updateText();
                    this.increment();
                }
            }
        }

        pause() {
            this.running = false;
            clearInterval(this.intervalID);
        }

        increment() {
            var overflow = true;
            for(var index = this.time.length-1; index >= 0 && overflow; index--) {
                var digit = this.time[index];
                digit.value++;
                if(digit.value == digit.max) {
                    digit.value = 0;
                    overflow = true;
                } else {
                    overflow = false;
                }
            }
        }

        updateText() {
            var string = "";
            $(this.time).each((index, digit) => {
                string += "{0}{1}".format(digit.value, digit.prefix);
                if(index != this.time.length-1) string += " ";
            });
            this.text.html(string);
        }
    };

    return {
        "init": init,
        "timers": timers,
        "Timer": Timer
    };
});



