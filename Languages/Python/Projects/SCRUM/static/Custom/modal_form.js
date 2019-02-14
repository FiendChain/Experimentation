var ModalForm = new(function() {
    var forms = [];

    function init() {
        var modal_forms = $("form.modal-form");
        modal_forms.each((index, modal_form) => {
            var form = new ModalForm(modal_form);
            forms.push(form);
        });
        bind_buttons();
    }

    // searchs and binds buttons
    function bind_buttons() {
        var buttons = $("button[data-target]");
        buttons.each((index, button) => {
            bind_button(button);
        });
    }

    function bind_button(button) {
        var button = $(button);
        var id = button.attr("data-target");
        forms.forEach(form => {
            if(form.id == id) {
                button.unbind("click");
                button.click(() => {
                    var modal_form = form.modal_form;
                    form.modal_form.modal('show');
                    var title = button.attr("title");
                    var get_url = button.attr("get-url");
                    var post_url = button.attr("post-url");
                    if(title) modal_form.find("[name='title']").html(title);
                    // fill form with get response, otherwise clear
                    if(get_url) {
                        form.load_modal_form(get_url);
                    } else {
                        modal_form.find("input").val(null);
                    }
                    if(post_url) form.submit_modal_form(post_url);
                });
            }
        });
    }

    class ModalForm {
        constructor(selector) {
            this.modal_form = $(selector);
            this.template = $("template#modal_form").html();
            this.createModalForm();
        }

        createModalForm() {
            this.wrap_modal_form();
        }

        wrap_modal_form() {
            var wrapper = $(this.template).clone();
            var title = this.modal_form.attr("title");
            var id = this.modal_form.attr("id");
            this.id = id;
            var form = this.modal_form.clone();
            wrapper.attr("id", id);
            wrapper.find("[name='title']").html(title);
            wrapper.find("[name='body']").html(form);
            // replace modal form
            this.modal_form.replaceWith(wrapper);
            this.modal_form = $(wrapper);
            form.removeClass("modal-form");
        }
        
        load_modal_form(url) {
            var response = $.getJSON(url);
            var form = this.modal_form.find("form");
            response.done(data => {
                $.each(data, function(key, value){
                    $(form).find('[name='+key+']').val(value);
                });
            });
            response.fail(error => {
                flash_message(this.modal_form, error.responseJSON.text, "danger");
            });
        }
        
        submit_modal_form(url) {
            var form = this.modal_form.find("form");
            form.unbind('submit');
            form.submit(event => {
                $.post(url, 
                    $(form).serializeArray(), 
                    response => {
                        flash_message(this.modal_form, response.message, response.category);
                        if(response.refresh == true) {
                            refreshPageWithoutResubmit(100);
                        }
                    },
                    'json'
                );
                event.preventDefault();
                return false;
            });
        }
    };
    
    return {
        "init": init,
        "forms": forms,
        "ModalForm": ModalForm,
        "bind_buttons": bind_buttons
    };
});
