
var fmax = 1;

$('#fiszka').flip({trigger: 'manual', axis:'x'});


function flipped(){	
	$('#fiszka').flip(true);
	$('.fresponse').fadeIn("slow");
}
function restore(){
	$('#fiszka').flip(false);
	$('.fresponse').fadeOut("fast");
}
$('#fiszka').click(flipped);
$('.fresponse').click(restore);