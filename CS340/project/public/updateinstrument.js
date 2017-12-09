function updateInstrument(id){
    $.ajax({
        url: '/instruments/' + id,
        type: 'PUT',
        data: $('#update-instrument').serialize(),
        success: function(result){
            window.location.replace("./");
        }
    })
};
