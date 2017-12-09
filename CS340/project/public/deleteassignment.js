function deleteAssignment(bmid){
    $.ajax({
        url: '/bands/remove_assignment/' + bmid,
        type: 'DELETE',
        success: function(result){
            window.location.reload(true);
        }
    })
};
