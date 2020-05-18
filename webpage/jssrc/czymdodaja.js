function czymdodaja(){
	if($(window).width()<334){
		$('.responses').css('min-height', '360px');
	}
	else if($(window).width()<768){
		$('.responses').css('min-height', '180px');
	}
	
	else{
		$('.responses').css('min-height', '90px');
	}
}

$(window).load(czymdodaja);
$(window).resize(czymdodaja);