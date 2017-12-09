function deleteInstrument(id){
    $.ajax({
        url: '/instruments/' + id,
        type: 'DELETE',
        success: function(result){
            window.location.reload(true);
        }
    })
};
