// Start timer for a progress bar
function startTimer(buttonID, barID, duration) {
    var button = document.getElementById(buttonID); // Initialise elements
    var bar = document.getElementById(barID);
    button.disabled = true;                                                    
    bar.style.cursor = 'progress';
    var fps = 50;                       // Get refresh rate of progress bar                                                              
    var refreshRate = 1000/fps;
    var increment = 100/(duration/refreshRate);
    var intervalID = setInterval(startProgressBar, refreshRate);
    var barWidth = 0;                   // Start incrementing the progress bar
    function startProgressBar() {
        if(barWidth >= 100) {
            button.disabled = false;
            clearInterval(intervalID);
            bar.innerHTML = 'Done!';
            bar.style.cursor = 'default';
        } else {
            barWidth += increment;
            bar.style.width = barWidth + '%';
            // Don't show percentage if bar is too narrow
            if(barWidth < 5) {
                bar.innerHTML = '';
            } else {
                bar.innerHTML = Math.trunc(barWidth) + '%'
            }
        }
    }
}

// Create countdown object
function createCountdown(buttonID, barID, duration) {
    var countdown = document.createElement('div');  
    countdown.className = 'countdown';
    var button     = createButton(buttonID, barID, duration);                    
    var barOutline = createBar(barID);
    countdown.appendChild(button);
    countdown.appendChild(barOutline);
    return countdown;
}

// Create progressbar
function createBar(barID) {
    var barOutline = document.createElement('div');
    var bar = document.createElement('div'); 
    barOutline.className = 'progressBar';
    bar.id = barID;
    barOutline.appendChild(bar);
    return barOutline;
}

// Create the button
function createButton(buttonID, barID, duration) {
    var button = document.createElement('button');  
    button.className = 'small';
    button.id       = buttonID;
    button.barID    = barID;
    button.duration = duration;
    var onclickString = "startTimer(this.id, this.barID, this.duration);"
    button.setAttribute('onclick', onclickString);
    return button;
}

