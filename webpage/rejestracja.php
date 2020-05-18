<?php
	
	session_start();
	
	$_SESSION['pageid'] = 'rejestracja';
	
	if(isset($_POST['email'])){
		
		// Udana walidacja
		$alles_klar=true;
		
		// Sprawdź poprawność wpisanych pól
		$login=$_POST['login'];
		$email=$_POST['email'];
		$emailB=$_POST['email'];
		$haslo1=$_POST['haslo1'];
		$haslo2=$_POST['haslo2'];
		
		$emailB=filter_var($email, FILTER_SANITIZE_EMAIL);
		
		// Sprawdź długość loginu
		if((strlen($login)<3) || (strlen($login)>20)){
			$alles_klar=false;
			$_SESSION['e_login']="Login musi zawierać od 3 do 20 znaków!";
		}
		
		// Sprawdź poprawność liter
		if(!ctype_alnum($login)){
			$alles_klar=false;
			$_SESSION['e_login']="Login może składać się tylko z liter i cyfr (bez polskich znaków)";
		}
		
		// Sprawdź poprawność emaila
		
		
		if((filter_var($emailB, FILTER_VALIDATE_EMAIL)==false) || ($email!=$emailB)){
			$alles_klar=false;
			$_SESSION['e_email']="Podaj poprawny adres e-mail";
		}
		
		// Sprawdź poprawność hasła
		
		if((strlen($haslo1)<8) || (strlen($login)>20)){
			$alles_klar=false;
			$_SESSION['e_haslo']="Hasło musi zawierać od 8 do 20 znaków!";
		}
	
		if($haslo1 != $haslo2){
			$alles_klar=false;
			$_SESSION['e_haslo']="Wpisane hasła są różne";
		}
		
		$haslo_hash = password_hash($haslo1, PASSWORD_DEFAULT);
		
		// Sprawdź regulamin
		if(!isset($_POST['regulamin'])){
			$alles_klar=false;
			$_SESSION['e_regulamin']="Potwierdź akceptację regulaminu";	
		}
		
		require_once "connect.php";
		
		// Zapamiętaj wprowazdone dane
		
		$_SESSION['fr_login']=$login;
		$_SESSION['fr_haslo']=$haslo_hash;
		
		if(isset($_POST['regulamin']))$_SESSION['fr_regulamin']=true;
		mysqli_report(MYSQLI_REPORT_STRICT);
		
		try{
			$polaczenie=@new mysqli($host, $db_user, $db_password, $db_name);
			
			if($polaczenie->connect_errno!=0){
				echo "Error!: ".$polaczenie->connect_errno." Opis: ".$polaczenie->connect_error;
			}
			else{
				//czy mail już istnieje
				$result=$polaczenie->query("SELECT id FROM uzytkownicy WHERE email='$email'");
				
				if(!$result) throw new Exception($polaczenie->error);
				
				$iletakich=$result->num_rows;
				if($iletakich>0){
					$alles_klar=false;
					$_SESSION['e_email']="Istnieje już konto przypisane do tego adresu email";
				}
				
				// czy login już jest zajety
				$result=$polaczenie->query("SELECT id FROM uzytkownicy WHERE email='$login'");
				
				if(!$result) throw new Exception($polaczenie->error);
				
				$iletakich=$result->num_rows;
				if($iletakich>0){
					$alles_klar=false;
					$_SESSION['e_login']="Istnieje już gracz o podanym loginu";
				}
				
				
				if($alles_klar==true){
					if($polaczenie->query("INSERT INTO uzytkownicy VALUES(NULL, '$login', '$haslo_hash', '$email', now(), 0)"))
					{
						$_SESSION['udanarejestracja']=true;
						header('Location: witamy.php');
					}
				}
				else{
					throw new Exception($polaczenie->error);
				}
				
				$polaczenie->close();
			}
			
		}
		catch(Exception $e){
			echo '<span style="color: red;">Błąd serwera! Przepraszamy za niedogodności!</span>';
			// echo '<br/>informacja deweloperska: '.$e;
		}
		
		if($alles_klar==true){
			// echo "Udana walidacja"; exit();
		}
	}
	
?>


<!DOCTYPE HTML>
<html lang="pl">
<head>
	<meta charset="utf-8">
	
	<title>Projekt zaliczeniowy z przedmiotu aplikacje mobilne i internetowe </title>
	<meta name="description" content="Projekt zaliczeniowy">
	<meta name="keywords" content="projekt, zaliczenie, wykładu">
	<meta name="author" content="Jan Hałasiński">
	<meta http-equiv="X-Ua-Compatible" content="IE=edge">
	 <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">

	
	<link rel="stylesheet" href="css/bootstrap.min.css">
	<link rel="stylesheet" href="main.css">
	<link href="https://fonts.googleapis.com/css?family=Open+Sans:400,700&amp;subset=latin-ext" rel="stylesheet">

	<script src="https://code.jquery.com/jquery-3.3.1.slim.min.js" integrity="sha384-q8i/X+965DzO0rT7abK41JStQIAqVgRVzpbzo5smXKp4YfRvH+8abtTE1Pi6jizo" crossorigin="anonymous"></script>
	
	<script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.3/umd/popper.min.js" integrity="sha384-ZMP7rVo3mIykV+2+9J3UJ46jBk0WLaUAdn689aCwoqbBJiSnjAK/l8WvCWPIPm49" crossorigin="anonymous"></script>
	
	<script src="js/bootstrap.min.js"></script>
	
</head>

<body>

<header>
	<?php
		include('./nav.php');
	?>
<header>

<main>
	<section>
		<div id="okno_rejestracji" class="col-md-6 offset-md-3">
			<form method="post"> Login: <br/> <input type="text" name="login" /><br/>
				
				<?php
					if(isset($_SESSION['e_login'])){
						echo '<div class="error">'.$_SESSION['e_login'].'</div>';
						unset($_SESSION['e_login']);
					}
				?>
				
				E-mail:  <br/> <input type="mail" name="email" /><br/>
				
				<?php
					if(isset($_SESSION['e_email'])){
						echo '<div class="error">'.$_SESSION['e_email'].'</div>';
						unset($_SESSION['e_email']);
					}
				?>
			
				Hasło: <br/> <input type="password" name="haslo1" /><br/>
					
				Powtórz hasło: <br/> <input type="password" name="haslo2" /><br/><br/>
				
				<?php
					if(isset($_SESSION['e_haslo'])){
						echo '<div class="error">'.$_SESSION['e_haslo'].'</div>';
						unset($_SESSION['e_haslo']);
					}
				?>
			
				<label>
					<input type="checkbox" name="regulamin" /> Akceptuję Regulamin <br/>
					<?php
						if(isset($_SESSION['e_regulamin'])){
							echo '<div class="error">'.$_SESSION['e_regulamin'].'</div>';
							unset($_SESSION['e_regulamin']);
						}
					?>
				</label>
				
				<br/>
				<?php
					if(isset($_SESSION['e_bot'])){
						echo '<div class="error">'.$_SESSION['e_bot'].'</div>';
						unset($_SESSION['e_bot']);
					}
				?>
				<br/>
				<input type="submit" value="Utwórz konto!" />
				
			</form>
		</div>
	</section>		
</main>

<footer>
	<?php include("./footer.php"); ?>
</footer>

</body>
</html>