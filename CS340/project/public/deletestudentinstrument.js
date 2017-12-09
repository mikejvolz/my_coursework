function deleteStudentInstrument(siid){
    $.ajax({
        url: '/instruments/delete_assignment/' + id,
        type: 'DELETE',
        success: function(result){
            window.location.reload(true);
        }
    })
};
