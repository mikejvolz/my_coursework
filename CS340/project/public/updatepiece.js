function updatePiece(id){
    $.ajax({
        url: '/music/' + id,
        type: 'PUT',
        data: $('#update-piece').serialize(),
        success: function(result){
            window.location.replace("./");
        }
    })
};
