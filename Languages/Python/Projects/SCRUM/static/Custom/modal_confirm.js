var ModalConfirm = new(function () {
    var buttons = [];

    function init() {
        bind_buttons();
    }

    function bind_buttons() {
        var modal_confirm = $("div#modal_confirm");
        var buttons = $("button.modal-confirm");
        buttons.each((index, button) => {
            bind_modal_confirm_button(button, modal_confirm);
            buttons.push(button);
        });
    }

    function bind_modal_confirm_button(button, modal_confirm) {
        $(button).click(() => {
            modal_confirm.modal('show');
            var url = $(button).attr('url');
            var title = $(button).attr('title');
            var message = $(button).attr('message');
            modal_confirm.find("[name='title']").html(title);
            modal_confirm.find("[name='message']").html(message);
            submit_modal_confirm(modal_confirm, url);
        });
    }

    function submit_modal_confirm(modal_confirm, url) {
        var button = $(modal_confirm).find("[name='confirm']");
        button.click(() => {
            $.ajax({
                url: url,
                type: 'DELETE',
                success: response => {
                    flash_message(modal_confirm, response.message, response.category);
                    if(response.refresh == true) {
                        refreshPageWithoutResubmit();
                    }
                }
            });
        });
    }

    return {
        "init": init,
        "buttons": buttons,
        "bind_buttons": bind_buttons
    };
});