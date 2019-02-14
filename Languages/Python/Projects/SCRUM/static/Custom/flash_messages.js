function flash_message(element_id, string, category="danger") {
    var container = $(element_id).find("#flash_message_container");
    var template = $("template#flash_message").html().trim();
    var wrapper = $(template);
    wrapper.find("strong.text").text(upperCase(category)+"!");
    wrapper.find("span.text").text(string);

    wrapper.css("display","");
    wrapper.addClass("alert-"+category);
    container.append(wrapper);
}

function upperCase(string) {
    return string[0].toUpperCase() + string.slice(1);
}