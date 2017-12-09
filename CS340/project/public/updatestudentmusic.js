function updateStudentMusic(id){
    $.ajax({
        url: '/student-music/' + id,
        type: 'PUT',
        data: $('#update-student-music').serialize(),
        success: function(result){
            window.location.replace("./");
        }
    })
};
