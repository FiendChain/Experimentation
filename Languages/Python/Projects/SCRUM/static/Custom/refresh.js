// refresh the page without resubmitting previous post
function refreshPageWithoutResubmit(delay=900) {
    window.setTimeout(function() {
        window.location.href = window.location.pathname;
    }, delay);
}