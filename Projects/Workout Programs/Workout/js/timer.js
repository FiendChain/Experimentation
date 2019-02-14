function toggleTimer(button) {
    if(button.timerEnabled == undefined) {
        button.timerEnabled = false;
    }
    // Toggle the button's timer
    if(button.timerEnabled == false) {
        button.timerEnabled = true;
        button.innerHTML = '0h 0m 0s';
        var time = {"h":0, "m":0, "s":0};
        button.intervalID = setInterval(startTimer, 1000);
    } else {
        clearInterval(button.intervalID);
        button.timerEnabled = false;
        button.innerHTML = 'Start Timer';
    }
    // Increment time and update button text
    function startTimer() {
        time.s++;
        if(time.s >= 60) {
            time.s = 0;
            time.m++;
            if(time.m >= 60) {
                time.m = 0;
                time.h++;
            }
        }
        button.innerHTML = time.h+'h '+time.m+'m '+time.s+'s ';
    }
}

