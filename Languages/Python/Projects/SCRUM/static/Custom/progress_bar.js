class ProgressBar {
    constructor(duration, fps=1) {
        this.setTime(duration, fps);
        this.init();
        this.assemble();
    }

    init() {
        this.running = false;
        this.background = $("<div class='progress'></div>");
        this.background.css({
            "height": "25px"
        });
        this.bar = $("<div class='progress-bar progress-bar-striped bg-success one-fps-bar' role='progressbar' aria-valuemin='0' aria-valuemax='100'></div>");
        this.text = $("<strong></strong>");
        this.reset();
        this.stop();
    }

    assemble() {
        this.background.append(this.bar);
        this.bar.append(this.text);
    }

    setTime(duration, fps) {
        this.duration = duration;
        this.fps = this.fps;
        this.refreshRate = 1000/fps;                    // in milliseconds
        var ratio = this.refreshRate/(duration*1000);   // ratio of refresh interval to duration
        this.increment = 100*ratio;                     // scale to 100
    }

    reset() {
        this.running = false;
        this.barWidth = 0;
        this.bar.css("width", 0);
        this.bar.addClass("progress-bar-animated");
    }

    start() {
        this.reset();
        this.running = true;
        this.background.css("cursor", "default");
        var timer = setInterval(increment.bind(this), this.refreshRate);
        function increment() {
            if(this.barWidth >= 100) {
                clearInterval(timer);
                this.stop();
            } else {
                this.barWidth += this.increment;
                this.bar.css("width", this.barWidth+"%")
            }
            this.updateText();
        }
    }

    stop() {
        this.running = false;
        this.background.css("cursor", "pointer");
        this.bar.removeClass("progress-bar-animated");
    }

    updateText() {
        if(this.barWidth >= 100)    this.text.html("Done");
        else if(this.barWidth < 10) this.text.html("");
        else                        this.text.html(Math.trunc(this.barWidth)+"%");
    }

    click(func) {
        this.background.click(() => {
            if(this.running === false) {
                func();
                this.start();
            }
        });
    }
};