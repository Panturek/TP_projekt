<?php
    if((isset($_SESSION['zalogowany'])==true)&&($_SESSION['zalogowany']==true)){
        
    }
    else{
        $_SESSION['zalogowany'] = false;
    }
    
    $_SESSION ['zalogowany']; 
?>
    <?php echo '<div class = "d-none" id="page">'.$_SESSION['pageid'].'</div>'; ?>
    <nav class="navbar navbar-dark sticky-top navbar-expand-md">
                    
        <nav class="navbar navbar-dark w-100 navbar-expand-lg">
        
            <a class="navbar-brand" href="index.php"><img src="img/logo.png" width="30" height="30" class="d-inline-block mr-1 align-bottom" alt=""> Projekt.pl </a>
        
            <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#mainmenu" aria-controls="mainmenu" aria-expanded="false" aria-label="Przełącznik nawigacji">
                <span class="navbar-toggler-icon"></span>
            </button>
        
            <div class="collapse navbar-collapse" id="mainmenu">
            
                <ul class="navbar-nav">
                
                    <li class="nav-item" id = "index">
                        <a class="nav-link" href="index.php"> Start </a>
                    </li>
                    
                    <li class="nav-item" id = "plany">
                        <a class="nav-link" href="plans.php"> plany </a>
                    </li>
                    
                    <?php
                        if($_SESSION['zalogowany'] == false){
                            echo '<li class="nav-item" id = "rejestracja">';
                            echo '<a class="nav-link" href="rejestracja.php"> Rejestracja </a>';
                            echo '</li>';
                        
                            echo '<li class="nav-item" id = "loginPanel">';
                            echo '<a class="nav-link d-lg-none" href="loginpanel.php"> Zaloguj </a>';
                            echo '</li>';
                        }
                        else
                        {
                            echo '<li class="nav-item d-lg-none" id = "wyloguj">';
                            echo '<a class="nav-link" href="logout.php"> Wyloguj </a>';
                            echo '</li>';
                        
                        }
                    ?>
                </ul>
            
            </div>
            
            <div class="mr-auto d-none d-lg-inline">
                <?php 
                    if($_SESSION['zalogowany'] == false){
                        echo '<form class="form-inline" action="zaloguj.php" method="post">';
                                
                        echo '<input class="form-control mr-1 logincontrol" name="login" type="text" placeholder="Login" aria-label="login" method="post">';
                            
                        echo '<input class="form-control mr-1 logincontrol" name="haslo" type="password" placeholder="Hasło" aria-label="Password" method="post">';
                        echo '<button class="btn btn-light" type="submit">Zaloguj</button>';                    
                        echo '</form>';
                    } 
                    else{
                        echo '<a class="d-md-block" id="wyloguj" href="logout.php"> Wyloguj </a>';                        
                    }
                ?>
                
            </div>

        </nav>
        
    </nav>
    
    <script>
        var page = document.getElementById('page').textContent;
        document.getElementById(page).classList.add('active');
    </script>
