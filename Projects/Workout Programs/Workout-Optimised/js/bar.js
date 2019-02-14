// Start timer for a progress bar
function startTimer(button, bar, duration) {
    console.log(duration);
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
function createCountdown(duration) {
    var countdown = document.createElement('div');  
    countdown.className = 'countdown';
    var button = createButton(duration);      
    var bar = createBar();              
    button.bar = bar.children[0];
    countdown.appendChild(button);
    countdown.appendChild(bar);
    return countdown;
}

// Create progressbar
function createBar() {
    var barOutline = document.createElement('div');
    var bar = document.createElement('div'); 
    barOutline.className = 'progressBar';
    barOutline.appendChild(bar);
    return barOutline;
}

// Create the button
function createButton(duration) {
    var button = document.createElement('button');  
    button.className = 'small';
    button.duration = duration;
    var onclickString = "startTimer(this, this.bar, this.duration);"
    button.setAttribute('onclick', onclickString);
    return button;
}

