function deletePiece(id){
    $.ajax({
        url: '/music/' + id,
        type: 'DELETE',
        success: function(result){
            window.location.reload(true);
        }
    })
};
