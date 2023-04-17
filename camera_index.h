//HTML code for /about page
const char index_html[] = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="icon" type="image/x-icon" href="data:image/png;base64,/9j/4AAQSkZJRgABAQEAYABgAAD/4QAiRXhpZgAATU0AKgAAAAgAAQESAAMAAAABAAEAAAAAAAD/2wBDAAIBAQIBAQICAgICAgICAwUDAwMDAwYEBAMFBwYHBwcGBwcICQsJCAgKCAcHCg0KCgsMDAwMBwkODw0MDgsMDAz/2wBDAQICAgMDAwYDAwYMCAcIDAwMDAwMDAwMDAwMDAwMDAwMDAwMDAwMDAwMDAwMDAwMDAwMDAwMDAwMDAwMDAwMDAz/wAARCAAUABADASIAAhEBAxEB/8QAHwAAAQUBAQEBAQEAAAAAAAAAAAECAwQFBgcICQoL/8QAtRAAAgEDAwIEAwUFBAQAAAF9AQIDAAQRBRIhMUEGE1FhByJxFDKBkaEII0KxwRVS0fAkM2JyggkKFhcYGRolJicoKSo0NTY3ODk6Q0RFRkdISUpTVFVWV1hZWmNkZWZnaGlqc3R1dnd4eXqDhIWGh4iJipKTlJWWl5iZmqKjpKWmp6ipqrKztLW2t7i5usLDxMXGx8jJytLT1NXW19jZ2uHi4+Tl5ufo6erx8vP09fb3+Pn6/8QAHwEAAwEBAQEBAQEBAQAAAAAAAAECAwQFBgcICQoL/8QAtREAAgECBAQDBAcFBAQAAQJ3AAECAxEEBSExBhJBUQdhcRMiMoEIFEKRobHBCSMzUvAVYnLRChYkNOEl8RcYGRomJygpKjU2Nzg5OkNERUZHSElKU1RVVldYWVpjZGVmZ2hpanN0dXZ3eHl6goOEhYaHiImKkpOUlZaXmJmaoqOkpaanqKmqsrO0tba3uLm6wsPExcbHyMnK0tPU1dbX2Nna4uPk5ebn6Onq8vP09fb3+Pn6/9oADAMBAAIRAxEAPwD2v/gvR/wUN+LHw5+Odr8Hfhn4m1T4ZaTZ2NpPqPiG0T7Lda3qFzudLGG8ZlW3jji8pmZHVmknVWKoCTY/4IKf8FBPiv8AFT4y6l8H/iZ4j1H4mab/AGddXmn+JblftN1o17bvGZLCa8RnW4jkjaRldnZleB1DOhUr4h/wX4/ZKn+CH7dt18QNS1i3utD+MMjalYnU3WGz0l7eysrO6DSmZZDNBshuLcRDf+9KqkoSRTZ/4N+/2TZvjH+3FH8RtP1i1ttE+Dri7uhpjCey1mS6sL6yg2y+c0gmlEstzOJRvzEiskYZFH1XssP/AGdey2ve2t/XffQ+RVbEf2pytve1r6cvpttqfqX+3Z/wSq+Gv/BTOXwtN8SNQ8ZRxeDUuY9PttH1RbSDdceUZJHUxvufESKDngZHc5X9hb/glj8N/wDgmXF4qPw31DxlLb+Mvs32+11jVFu4Fe383ZJGojTa5ErKx5yAo/hFFFeO6s/qvJd27dN+x7nsYfW/acqv3trt3P/Z">
    <title>Face App</title>
    <style>
      *{
        margin: 0;
        padding: 0;
        box-sizing: border-box;
        }
    
        body {
            font-family:Verdana, Geneva, Tahoma, sans-serif;
            background-image: linear-gradient(45deg,rgb(255, 255, 255),#fff,#fff,rgb(141, 207, 158),rgb(123, 190, 192),rgb(130, 129, 180),
            rgb(160, 103, 132),rgb(145, 70, 74), rgb(122, 55, 55));
            background-size: 2000% 2000%;
            background-repeat: no-repeat;
            animation: gradient 20s ease infinite;
            }
    
            @keyframes gradient {
                0% {
                    background-position: 0% 50%;
                }
    
                50% {
                    background-position: 100% 50%;
                }
    
                100% {
                    background-position: 0% 50%;
                }
            }
    
        .container {
            width:100%;
            height:100vh;
            } 
        
        a{
            text-decoration:none;
            color: #fff;
        }
    
        li{
            list-style: none;
        }
       
        /* NAVBAR STYLING STARTS */
    .navbar {
        display: flex;
        align-items: center;
        justify-content: space-between;
        padding: 10px;
        background-color: teal;
        color: #fff;
        border-radius: 1px;
       }
       
       .nav-links a {
        color: #fff;
       }
    
       .logo{
        display:flex;
        padding: 5px;
        margin-right:5px;
        flex-direction: row;
        justify-content: flex-start;
        align-items: center;
    }
    
    .logo>img{
        width:20%;
        margin-right:5px;
        border-radius: 5px;
    }
    
    .logo>p{
        font-size: 1.2em;
    }
       
       .menu {
        display: flex;
        gap: 1em;
        font-size: 18px;
       }
    
       .menu li:hover {
        background-color: #4c9e9e;
        border-radius: 5px;
        transition: 0.3s ease;
       }
    
       .menu li {
        padding: 5px 14px;
       }
    
       /* CHECKBOX HACK */
    input[type=checkbox]{
        display: none;
       } 
       /*HAMBURGER MENU*/
       .hamburger {
        display: none;
        font-size: 24px;
        user-select: none;
       }
    
       .banner{
        display:flex;
        background-color: #00000093;
        height: 70vw;
        max-height:400px;
        flex-direction: column;
        justify-content: center;
        margin:auto;
        border-radius: 0px 0px 15px 15px;
        box-shadow: 0px 0px 10px #000;
       }
    
        .landing{
        display:flex;
        flex-direction: column;
        padding:15px;
        justify-content: space-between;
        max-width:80vw;
        margin: 0px auto;
        }
      
       .info{
        max-width: 700px;
        color:white;
        text-align:center;
        font-size: 1.7em;
        padding:15px;
        line-height: 2.1rem;
        margin: 0px auto;
        }
    
        .what-to-do{
            text-align:center;
            background-image: linear-gradient(120deg,rgb(13, 37, 37,0.74),rgb(22, 112, 112,0.74),rgb(3, 36, 46,0.74)); 
            color:white;
            margin: 15px auto;
            width:100%;
            font-size: 1.5em;
            padding:15px;
            line-height: 26px;
            box-shadow: 0px 0px 10px rgb(0, 0, 0);
            border-radius:5px;
        }
        
        .buttons{
            width:100%;
            height:15vw;
            display: flex;
            justify-content: space-between;
            margin: 15px auto 30px auto;
            text-align: center;
            }
    
        #toggle-stream, #toggle-manage, #toggle-door{
            width:30.5%;
            height:100%;
            font-size:1.8em;
            box-shadow: 0px 0px 10px rgb(0, 0, 0);
            border-radius: 1px;
            border:none;
            color:white;
            border-radius: 5px;
            background-color: rgba(12, 58, 61, 0.74);
        }
    
    
        #toggle-stream:hover, #toggle-manage:hover, #toggle-door:hover{
        
        background-image:none;
        transition: 0.5s ease-in-out;
        background-color: rgb(1, 26, 32);
        border:2px solid white;
        border-radius:5px;
        }
    
        #toggle-stream:active, #toggle-manage:active, #toggle-door:active{
            background-color: rgb(3, 48, 59);
            transition: none;
        }

        @media (max-width: 768px) {
        .menu { 
         display:none;
         position: absolute;
         background-color:rgba(0, 128, 128, 0.9);
         right: 0;
         text-align: center;
         padding: 16px 0;
         height: auto;
         min-width: 300px;
         overflow: auto;
        }
     
        .menu li:hover {
         display: inline-block;
         background-color:#4c9e9e;
         transition: 0.3s ease;
        }
        .menu li + li {
         margin-top: 12px;
        }
        input[type=checkbox]:checked ~ .menu{
         transition:0.5s ease;
         display: block;
         }
     
         .hamburger {
         display: block;
        }

        .landing{
            padding:10px;
            max-width:100vw;
            flex-direction: column;
           }

        .buttons{
           height:25vw;
        }

        .logo>p{
            font-size: 1em;
        }

        #toggle-stream, #toggle-manage, #toggle-door{
            font-size:1.3em;
        }
        }
    </style>
  
    </head>
    <body>
    
    <main class="container">
        <nav class="navbar">
            <div class="logo">
              <img src="data:image/png;base64,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" alt="face logo" />
              <p><a href="/">faceApp</a></p>
            </div>
            <ul class="nav-links">
              <input type="checkbox" id="checkbox_toggle" />
              <label for="checkbox_toggle" class="hamburger">&#9776;</label>
                <div class="menu">
                <li><a href="/">Home</a></li>
                <li><a href="/about.html">About</a></li>
                <li><a href="/logout.html">Logout</a></li>
              </div>
            </ul>
          </nav>

          <div class="banner">
            <p class="info">
              Security and automation has never been made more easy with the combination of biometrics.
              <!-- This application allows you to monitor, control and manage our 
              Face Recognition Security Door System. -->
          </p>
          </div>
        
          <!-- <img id ="banner" src="" alt="face-image"> -->

        <section class="landing">
            
            <p class="what-to-do">
                What will you like to do?
            </p>
            <section class="buttons">
                    <button id="toggle-stream">Stream</button>
                    <button id="toggle-manage">Manage</button>
                    <button id="toggle-door">Open Door</button>
            </section>
            
            </section>
    </main>
   <script>
    
  let value = 0;
let stream_btn = document.getElementById("toggle-stream");
let manage_btn = document.getElementById("toggle-manage");
let door_btn = document.getElementById("toggle-door");
let baseHost = document.location.origin;

//function to open the streaming page
stream_btn.addEventListener("click", function () {
  stream_btn.innerHTML = "Streaming";
  window.open(`${baseHost}` + "/streampage.html", "_self");
});

manage_btn.addEventListener("click", function () {
  window.open(`${baseHost}` + "/manage.html", "_self");
});

door_btn.addEventListener("click", function () {
  let query =`${baseHost}/control?var=door&val=1`
  let closed =`${baseHost}/control?var=door&val=0`
  fetch(query).then(response => {
    console.log("Door is opening");
  }); 
});
   </script> 
</body>
</html>
)rawliteral";

const char streampage_html[] = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="UTF-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <link rel="icon" type="image/x-icon" href="data:image/png;base64,/9j/4AAQSkZJRgABAQEAYABgAAD/4QAiRXhpZgAATU0AKgAAAAgAAQESAAMAAAABAAEAAAAAAAD/2wBDAAIBAQIBAQICAgICAgICAwUDAwMDAwYEBAMFBwYHBwcGBwcICQsJCAgKCAcHCg0KCgsMDAwMBwkODw0MDgsMDAz/2wBDAQICAgMDAwYDAwYMCAcIDAwMDAwMDAwMDAwMDAwMDAwMDAwMDAwMDAwMDAwMDAwMDAwMDAwMDAwMDAwMDAwMDAz/wAARCAAUABADASIAAhEBAxEB/8QAHwAAAQUBAQEBAQEAAAAAAAAAAAECAwQFBgcICQoL/8QAtRAAAgEDAwIEAwUFBAQAAAF9AQIDAAQRBRIhMUEGE1FhByJxFDKBkaEII0KxwRVS0fAkM2JyggkKFhcYGRolJicoKSo0NTY3ODk6Q0RFRkdISUpTVFVWV1hZWmNkZWZnaGlqc3R1dnd4eXqDhIWGh4iJipKTlJWWl5iZmqKjpKWmp6ipqrKztLW2t7i5usLDxMXGx8jJytLT1NXW19jZ2uHi4+Tl5ufo6erx8vP09fb3+Pn6/8QAHwEAAwEBAQEBAQEBAQAAAAAAAAECAwQFBgcICQoL/8QAtREAAgECBAQDBAcFBAQAAQJ3AAECAxEEBSExBhJBUQdhcRMiMoEIFEKRobHBCSMzUvAVYnLRChYkNOEl8RcYGRomJygpKjU2Nzg5OkNERUZHSElKU1RVVldYWVpjZGVmZ2hpanN0dXZ3eHl6goOEhYaHiImKkpOUlZaXmJmaoqOkpaanqKmqsrO0tba3uLm6wsPExcbHyMnK0tPU1dbX2Nna4uPk5ebn6Onq8vP09fb3+Pn6/9oADAMBAAIRAxEAPwD2v/gvR/wUN+LHw5+Odr8Hfhn4m1T4ZaTZ2NpPqPiG0T7Lda3qFzudLGG8ZlW3jji8pmZHVmknVWKoCTY/4IKf8FBPiv8AFT4y6l8H/iZ4j1H4mab/AGddXmn+JblftN1o17bvGZLCa8RnW4jkjaRldnZleB1DOhUr4h/wX4/ZKn+CH7dt18QNS1i3utD+MMjalYnU3WGz0l7eysrO6DSmZZDNBshuLcRDf+9KqkoSRTZ/4N+/2TZvjH+3FH8RtP1i1ttE+Dri7uhpjCey1mS6sL6yg2y+c0gmlEstzOJRvzEiskYZFH1XssP/AGdey2ve2t/XffQ+RVbEf2pytve1r6cvpttqfqX+3Z/wSq+Gv/BTOXwtN8SNQ8ZRxeDUuY9PttH1RbSDdceUZJHUxvufESKDngZHc5X9hb/glj8N/wDgmXF4qPw31DxlLb+Mvs32+11jVFu4Fe383ZJGojTa5ErKx5yAo/hFFFeO6s/qvJd27dN+x7nsYfW/acqv3trt3P/Z">
    <title>Stream</title>
    <style>
      *{
    margin: 0;
    padding: 0;
    box-sizing: border-box;
    }

    body {
        font-family:Verdana, Geneva, Tahoma, sans-serif;
        background-image: linear-gradient(45deg,rgb(255, 255, 255),#fff,#fff,rgb(141, 207, 158),rgb(123, 190, 192),rgb(130, 129, 180),
        rgb(160, 103, 132),rgb(145, 70, 74), rgb(122, 55, 55));
        background-size: 2000% 2000%;
        background-repeat: no-repeat;
        animation: gradient 20s ease infinite;
        }

        @keyframes gradient {
            0% {
                background-position: 0% 50%;
            }

            50% {
                background-position: 100% 50%;
            }

            100% {
                background-position: 0% 50%;
            }
        }

    .container {
        width:100%;
        height:100vh;
        } 
    
    a{
        text-decoration:none;
        color: #fff;
    }

    li{
        list-style: none;
    }
   
    /* NAVBAR STYLING STARTS */
.navbar {
    display: flex;
    align-items: center;
    justify-content: space-between;
    padding: 10px;
    background-color: teal;
    color: #fff;
    border-radius: 1px;
   }
   
   .nav-links a {
    color: #fff;
   }

   .logo{
    display:flex;
    padding: 5px;
    margin-right:5px;
    flex-direction: row;
    justify-content: flex-start;
    align-items: center;
}

.logo>img{
    width:20%;
    margin-right:5px;
    border-radius: 5px;
}

.logo>p{
    font-size: 1.2em;
}
   
   .menu {
    display: flex;
    gap: 1em;
    font-size: 18px;
   }

   .menu li:hover {
    background-color: #4c9e9e;
    border-radius: 5px;
    transition: 0.3s ease;
   }

   .menu li {
    padding: 5px 14px;
   }


input[type=checkbox]{
    display: none;
   } 
   .hamburger {
    display: none;
    font-size: 24px;
    user-select: none;
   }

    .form-page{
        border-radius: 10px;
        width: 100%;
        padding: 15px;
        margin: 15px auto;
        display: flex;
        flex-direction: column;
        justify-content: space-around;
        box-shadow: 0px 0px 10px rgb(3, 39, 33);
    }

    .form-page>a{
        color:white;
        text-align: center;
    }

    #stream-btn{
        padding:11px;
        border-radius:5px;
        font-size:1.2em;
        border:none;
        background-color: rgba(2, 26, 27);
        color:white;
    }

    #stream-btn:hover{
        transition:0.5s ease;
        background-color: black;
        color:gold;
    }

    #stream-btn:active{
       background-color: rgb(37, 37, 37);
    }

    #stream-btn{
        display: block;
        margin:10px auto;
        width:70vw;
        max-width:400px;
    }

    .streaming{
        width:80vw;
        max-width:800px;
        height:auto;
        margin: 15px auto;
        border-radius: 10px;
    }

    .return-home{
        max-width: 350px;
        background-color: #4c9e9e;
    }


    .hidden{
        display: none;
    }

    @media (max-width: 768px) {
        .menu { 
         display:none;
         position: absolute;
         background-color:rgba(0, 128, 128, 0.9);
         right: 0;
         text-align: center;
         padding: 16px 0;
         height: auto;
         min-width: 300px;
         overflow: auto;
        }
     
        .menu li:hover {
         display: inline-block;
         background-color:#4c9e9e;
         transition: 0.3s ease;
        }
        .menu li + li {
         margin-top: 12px;
        }
        input[type=checkbox]:checked ~ .menu{
         transition:0.5s ease;
         display: block;
         }
     
         .hamburger {
         display: block;
        }

        .logo>p{
            font-size: 1em;
        }
        }
</style>
  </head>
  <body>
    <main class="container">
      <nav class="navbar">
        <div class="logo">
          <img src="data:image/png;base64,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" alt="face logo" />
          <p><a href="/">faceApp</a></p>
        </div>
        <ul class="nav-links">
          <input type="checkbox" id="checkbox_toggle" />
          <label for="checkbox_toggle" class="hamburger">&#9776;</label>
          <div class="menu">
            <li><a href="/">Home</a></li>
            <li><a href="/about.html">About</a></li>
            <li><a href="/logout.html">Logout</a></li>
            </div>
        </ul>
      </nav>

      <figure class="streaming">
        <div id="stream-container" class="image-container hidden">
          <img id="stream" src="" />
        </div>
      </figure>

      <button id="stream-btn">Start Stream</button>
      <section class="form-page return-home">
        <a href="/">Return Home</a>
      </section>
    </main>

    <script>
      let stream_btn = document.getElementById("stream-btn");
let baseHost = location.origin;
let streamUrl = baseHost + ":81";



window.addEventListener("DOMContentLoaded", () => {
  stream_btn.addEventListener("click", function () {
    let img = document.getElementById("stream");
  img.src = `${streamUrl}/stream`;
  img.style.width = "100%";
  img.style.borderRadius = "10px";
    document.getElementById("stream-container").classList.toggle("hidden");
    if (stream_btn.innerHTML === "Start Stream") {
      stream_btn.innerHTML = "Stop Stream";
    } else {
      stream_btn.innerHTML = "Start Stream";
    }
  });
});

    </script>
  </body>
</html>

)rawliteral";

const char manage_html[] = R"rawliteral(
<!DOCTYPE html>
<html lang="en">

<head>
  <meta charset="UTF-8">
  <meta http-equiv="X-UA-Compatible" content="IE=edge">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Stream</title>
  <link rel="icon" type="image/x-icon"
    href="data:image/png;base64,/9j/4AAQSkZJRgABAQEAYABgAAD/4QAiRXhpZgAATU0AKgAAAAgAAQESAAMAAAABAAEAAAAAAAD/2wBDAAIBAQIBAQICAgICAgICAwUDAwMDAwYEBAMFBwYHBwcGBwcICQsJCAgKCAcHCg0KCgsMDAwMBwkODw0MDgsMDAz/2wBDAQICAgMDAwYDAwYMCAcIDAwMDAwMDAwMDAwMDAwMDAwMDAwMDAwMDAwMDAwMDAwMDAwMDAwMDAwMDAwMDAwMDAz/wAARCAAUABADASIAAhEBAxEB/8QAHwAAAQUBAQEBAQEAAAAAAAAAAAECAwQFBgcICQoL/8QAtRAAAgEDAwIEAwUFBAQAAAF9AQIDAAQRBRIhMUEGE1FhByJxFDKBkaEII0KxwRVS0fAkM2JyggkKFhcYGRolJicoKSo0NTY3ODk6Q0RFRkdISUpTVFVWV1hZWmNkZWZnaGlqc3R1dnd4eXqDhIWGh4iJipKTlJWWl5iZmqKjpKWmp6ipqrKztLW2t7i5usLDxMXGx8jJytLT1NXW19jZ2uHi4+Tl5ufo6erx8vP09fb3+Pn6/8QAHwEAAwEBAQEBAQEBAQAAAAAAAAECAwQFBgcICQoL/8QAtREAAgECBAQDBAcFBAQAAQJ3AAECAxEEBSExBhJBUQdhcRMiMoEIFEKRobHBCSMzUvAVYnLRChYkNOEl8RcYGRomJygpKjU2Nzg5OkNERUZHSElKU1RVVldYWVpjZGVmZ2hpanN0dXZ3eHl6goOEhYaHiImKkpOUlZaXmJmaoqOkpaanqKmqsrO0tba3uLm6wsPExcbHyMnK0tPU1dbX2Nna4uPk5ebn6Onq8vP09fb3+Pn6/9oADAMBAAIRAxEAPwD2v/gvR/wUN+LHw5+Odr8Hfhn4m1T4ZaTZ2NpPqPiG0T7Lda3qFzudLGG8ZlW3jji8pmZHVmknVWKoCTY/4IKf8FBPiv8AFT4y6l8H/iZ4j1H4mab/AGddXmn+JblftN1o17bvGZLCa8RnW4jkjaRldnZleB1DOhUr4h/wX4/ZKn+CH7dt18QNS1i3utD+MMjalYnU3WGz0l7eysrO6DSmZZDNBshuLcRDf+9KqkoSRTZ/4N+/2TZvjH+3FH8RtP1i1ttE+Dri7uhpjCey1mS6sL6yg2y+c0gmlEstzOJRvzEiskYZFH1XssP/AGdey2ve2t/XffQ+RVbEf2pytve1r6cvpttqfqX+3Z/wSq+Gv/BTOXwtN8SNQ8ZRxeDUuY9PttH1RbSDdceUZJHUxvufESKDngZHc5X9hb/glj8N/wDgmXF4qPw31DxlLb+Mvs32+11jVFu4Fe383ZJGojTa5ErKx5yAo/hFFFeO6s/qvJd27dN+x7nsYfW/acqv3trt3P/Z">
  <style>
    * {
      margin: 0;
      padding: 0;
      box-sizing: border-box;
    }

    body {
      font-family: Verdana, Geneva, Tahoma, sans-serif;
      background-image: linear-gradient(45deg, rgb(255, 255, 255), #fff, #fff, rgb(141, 207, 158), rgb(123, 190, 192), rgb(130, 129, 180),
          rgb(160, 103, 132), rgb(145, 70, 74), rgb(122, 55, 55));
      background-size: 2000% 2000%;
      background-repeat: no-repeat;
      animation: gradient 20s ease infinite;
    }

    @keyframes gradient {
      0% {
        background-position: 0% 50%;
      }

      50% {
        background-position: 100% 50%;
      }

      100% {
        background-position: 0% 50%;
      }
    }

    .container {
      width: 100%;
      height: 100vh;
    }

    a {
      text-decoration: none;
      color: #fff;
    }

    li {
      list-style: none;
    }

    .navbar {
      display: flex;
      align-items: center;
      justify-content: space-between;
      padding: 10px;
      background-color: teal;
      color: #fff;
      border-radius: 1px;
    }

    .nav-links a {
      color: #fff;
    }

    .logo {
      display: flex;
      padding: 5px;
      margin-right: 5px;
      flex-direction: row;
      justify-content: flex-start;
      align-items: center;
    }

    .logo>img {
      width: 20%;
      margin-right: 5px;
      border-radius: 5px;
    }

    .logo>p {
      font-size: 1.2em;
    }

    .menu {
      display: flex;
      gap: 1em;
      font-size: 18px;
    }

    .menu li:hover {
      background-color: #4c9e9e;
      border-radius: 5px;
      transition: 0.3s ease;
    }

    .menu li {
      padding: 5px 14px;
    }

    input[type=checkbox] {
      display: none;
    }

    .hamburger {
      display: none;
      font-size: 24px;
      user-select: none;
    }


    .form-page {
      border-radius: 10px;
      width: 100%;
      padding: 15px;
      margin: 15px auto;
      display: flex;
      flex-direction: column;
      justify-content: space-around;
      box-shadow: 0px 0px 10px rgb(3, 39, 33);
    }

  .hidden {
      display: none;
    }

    .manage-container {
      background-image: linear-gradient(120deg, #3f0606b3, #a71111b3, #3f0606b3);
      max-width: 400px;
    }

    .main-manage-buttons {
      display: flex;
      justify-content: space-around;
    }

    hr {
      margin: 10px auto 20px auto;
    }

    .btn {
      font-size: 1.1em;
      padding: 8px 12px;
      border-radius: 50px;
      border: none;
      margin-bottom: 10px;
    }

    .btn:hover {
      transition: 0.3s ease;
      background-color: black;
      color: gold;
    }

    .username,
    .password {
      padding: 10px;
      border-radius: 50px;
      border: none;
      margin-bottom: 1rem;
      outline: none;
      font-size: 1rem;
        }

    .stream-group {
      display: flex;
      flex-direction: column;
    }

    .stream-group>img {
      margin-bottom: 15px;
    }

    .face-buttons {
      display: flex;
      justify-content: space-around;
      margin-bottom: 10px;
    }

    .face-name {
      padding: 6px 15px;
      margin: 15px 0px;
      font-size: 1.2em;
      border-radius: 50px;
      border: none;
    }

    #face-list-container{
      color: white;
    }

    .login-group {
      margin: 1rem auto;
      width: 100%;
      max-width: 300px;
    }

    @media (max-width: 768px) {
      .menu {
        display: none;
        position: absolute;
        background-color: rgba(0, 128, 128, 0.9);
        right: 0;
        text-align: center;
        padding: 16px 0;
        height: auto;
        min-width: 300px;
        overflow: auto;
      }

      .menu li:hover {
        display: inline-block;
        background-color: #4c9e9e;
        transition: 0.3s ease;
      }

      .menu li+li {
        margin-top: 12px;
      }

      input[type=checkbox]:checked~.menu {
        transition: 0.5s ease;
        display: block;
      }

      .hamburger {
        display: block;
      }

      .landing {
        padding: 10px;
        max-width: 100vw;
        flex-direction: column;
      }

      .landing>img {
        width: 100%;
        height: auto;
      }

      .intro>p {
        margin-top: 15px;
      }

      .landing>p,
      .network-page>p {
        font-size: 1.3em;
      }

      .buttons {
        height: 25vw;
      }

      .logo>p {
        font-size: 1em;
      }

      #toggle-stream,
      #toggle-manage,
      #toggle-door {
        font-size: 1.3em;
      }
    }
  </style>
</head>

<body>
  <main class="container">
    <nav class="navbar">
      <div class="logo">
        <img
          src="data:image/png;base64,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"
          alt="face logo" />
        <p><a href="/">faceApp</a></p>
      </div>
      <ul class="nav-links">
        <input type="checkbox" id="checkbox_toggle" />
        <label for="checkbox_toggle" class="hamburger">&#9776;</label>
        <div class="menu">
          <li><a href="/">Home</a></li>
          <li><a href="/about.html">About</a></li>
          <li><a href="/logout.html">Logout</a></li>
          </div>
      </ul>
    </nav>

    <section class="form-page manage-container">
      <div id="face-stream-container" class="hidden">
        <div class="stream-group">
          <img src="" id="stream">
          <section id="faceID" class = hidden>
          <label for="face-name">Enter Face ID:</label>
          <input type="text" name="face-name" id="face-name" class="face-name">
          </section>
          <section id="face-buttons" class="face-buttons">
            <button id="face-detect-btn" class = "btn">Face Detect</button>
            <button id="start-enroll-btn" class = "btn">Start Enroll</button>
            <button id="face-enroll-btn" class = "btn">Face Enroll</button>
          </section>
        </div>
        <hr>
      </div>

      <div id="remove-face-container" class="hidden">
        <section class="stream-group">
          <label>Enter Face ID:</label>
          <input type="text" name="face-id" class="face-name" id="face-id">
          <button id="face-delete-btn">DELETE FACE</button>
          <button id="all-face-delete-btn">DELETE ALL FACES</button>
        </section>
        <hr>
      </div>

      <div id="login-detail-container" class="hidden">
        <section class="stream-group login-group">
        <input class="username" type="text" id ="USERNAME" placeholder="Enter New Username" />
        <input class="password" type="password" id = "PASSWORD" placeholder="Enter New Password" />
        <button id="submit-login-detail" class = "btn">SUBMIT</button>
      </section>
      </div>

      <div class="main-manage-buttons" id="main-manage-buttons">
        <button id="add-face" class="btn">Add Face</button>
        <button id="remove-face" class="btn">Remove Faces</button>
        <button id="details-btn" class = "btn">Login Detail</button>
     </div>
     <p style="text-align: center; font-size: 1.1rem;
      font-family: Calibri, sans-serif; font-weight: bold; color: white;" id = "status"></p>
      </section>
    
  </main>
  <script>
    let add_face_btn = document.getElementById("add-face");
    let remove_face_btn = document.getElementById("remove-face");
    let login_detail_btn = document.getElementById("details-btn");
    let settings_btn = document.getElementById("user-password");
    let main_manage_btn = document.getElementById("main-manage-buttons");
    let statusInfo = document.getElementById("status");
    let baseHost = location.origin;

    add_face_btn.addEventListener("click", () => {
      let pop_up = document.getElementById("face-stream-container");
      let stream = document.getElementById("stream");
      let streamUrl = `${baseHost}:81/stream`;
      stream.style.width = "100%";
      stream.style.borderRadius = "10px";
      stream.src = streamUrl;
      pop_up.classList.toggle("hidden");
      let detectValue = 0;
      let enrollValue = 0;
     
      let face_enroll_btn = document.getElementById("face-enroll-btn");
      face_enroll_btn.disabled = true;
      face_enroll_btn.addEventListener("click", ()=> {
        //enrollValue = !enrollValue;
        let enrollName = document.getElementById("face-name").value
        let query = `${baseHost}/control?var=face_enroll&val=${enrollName}`;
        fetch(query).then(response => {
          console.log(`Enrolling ${enrollName}`);
        });
      });

      let face_detect_btn = document.getElementById("face-detect-btn");
      face_detect_btn.addEventListener("click", ()=> {
        detectValue =! detectValue;
        let query = `${baseHost}/control?var=face_detect&val=${detectValue}`;
        fetch(query).then(reponse => {
          if(detectValue==true){ 
            start_enroll_btn.disabled = false;
            face_detect_btn.innerHTML ="Stop Detect"
            console.log("Face detection begins");
          } else {
            console.log("Face detection ends"); 
            face_detect_btn.innerHTML ="Face Detect"  
            start_enroll_btn.disabled = true;
          }
          
        });
      });

      let start_enroll_btn = document.getElementById("start-enroll-btn")
      start_enroll_btn.disabled = true
      start_enroll_btn.addEventListener("click", () => {
        document.getElementById("faceID").classList.toggle("hidden");
        face_enroll_btn.disabled = false
      })

    });

    remove_face_btn.addEventListener("click", () => {
        let i = 25;
        let interval = setInterval(()=>{
          i--;
          statusInfo.innerText = `Removing Faces in ${i} seconds`
            },1000);
      
      setTimeout(() => {
        statusInfo.innerText = "Reloading..."
        clearInterval(interval);
      }, 25000);

      setTimeout(() => {
        location.reload();
      }, 30000);
      
        let query = `${baseHost}/control?var=all-face-delete&val=0`;
        fetch(query).then(reponse => {
          console.log(`Faces deleted`)
        });
      });

     login_detail_btn.addEventListener("click", () => {
      let pop_up = document.getElementById("login-detail-container");
      pop_up.classList.toggle("hidden");
      let submit_btn = document.getElementById("submit-login-detail")
      
      submit_btn.addEventListener("click", () => {
        let user_ = document.getElementById("USERNAME").value;
        let pass_ = document.getElementById("PASSWORD").value;
        let query = `${baseHost}/control?USERNAME=${user_}&PASSWORD=${pass_}`;
        fetch(query).then(response=>{
        console.log("Changing Username and Password");
        statusInfo.innerText = "Submit Successful";
      })
      setTimeout(() => {
        statusInfo.innerText = "";
        }, 2000);
      })
    });
  </script>
</body>

</html>
)rawliteral";

const char about_html[] = R"rawliteral(
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="icon" type="image/x-icon"
        href="data:image/png;base64,/9j/4AAQSkZJRgABAQEAYABgAAD/4QAiRXhpZgAATU0AKgAAAAgAAQESAAMAAAABAAEAAAAAAAD/2wBDAAIBAQIBAQICAgICAgICAwUDAwMDAwYEBAMFBwYHBwcGBwcICQsJCAgKCAcHCg0KCgsMDAwMBwkODw0MDgsMDAz/2wBDAQICAgMDAwYDAwYMCAcIDAwMDAwMDAwMDAwMDAwMDAwMDAwMDAwMDAwMDAwMDAwMDAwMDAwMDAwMDAwMDAwMDAz/wAARCAAUABADASIAAhEBAxEB/8QAHwAAAQUBAQEBAQEAAAAAAAAAAAECAwQFBgcICQoL/8QAtRAAAgEDAwIEAwUFBAQAAAF9AQIDAAQRBRIhMUEGE1FhByJxFDKBkaEII0KxwRVS0fAkM2JyggkKFhcYGRolJicoKSo0NTY3ODk6Q0RFRkdISUpTVFVWV1hZWmNkZWZnaGlqc3R1dnd4eXqDhIWGh4iJipKTlJWWl5iZmqKjpKWmp6ipqrKztLW2t7i5usLDxMXGx8jJytLT1NXW19jZ2uHi4+Tl5ufo6erx8vP09fb3+Pn6/8QAHwEAAwEBAQEBAQEBAQAAAAAAAAECAwQFBgcICQoL/8QAtREAAgECBAQDBAcFBAQAAQJ3AAECAxEEBSExBhJBUQdhcRMiMoEIFEKRobHBCSMzUvAVYnLRChYkNOEl8RcYGRomJygpKjU2Nzg5OkNERUZHSElKU1RVVldYWVpjZGVmZ2hpanN0dXZ3eHl6goOEhYaHiImKkpOUlZaXmJmaoqOkpaanqKmqsrO0tba3uLm6wsPExcbHyMnK0tPU1dbX2Nna4uPk5ebn6Onq8vP09fb3+Pn6/9oADAMBAAIRAxEAPwD2v/gvR/wUN+LHw5+Odr8Hfhn4m1T4ZaTZ2NpPqPiG0T7Lda3qFzudLGG8ZlW3jji8pmZHVmknVWKoCTY/4IKf8FBPiv8AFT4y6l8H/iZ4j1H4mab/AGddXmn+JblftN1o17bvGZLCa8RnW4jkjaRldnZleB1DOhUr4h/wX4/ZKn+CH7dt18QNS1i3utD+MMjalYnU3WGz0l7eysrO6DSmZZDNBshuLcRDf+9KqkoSRTZ/4N+/2TZvjH+3FH8RtP1i1ttE+Dri7uhpjCey1mS6sL6yg2y+c0gmlEstzOJRvzEiskYZFH1XssP/AGdey2ve2t/XffQ+RVbEf2pytve1r6cvpttqfqX+3Z/wSq+Gv/BTOXwtN8SNQ8ZRxeDUuY9PttH1RbSDdceUZJHUxvufESKDngZHc5X9hb/glj8N/wDgmXF4qPw31DxlLb+Mvs32+11jVFu4Fe383ZJGojTa5ErKx5yAo/hFFFeO6s/qvJd27dN+x7nsYfW/acqv3trt3P/Z">
    <title>About</title>
    <style>
        * {
            margin: 0;
            padding: 0;
            box-sizing: border-box;
        }

        body {
            font-family: Verdana, Geneva, Tahoma, sans-serif;
            background-image: linear-gradient(45deg, rgb(255, 255, 255), #fff, #fff, rgb(141, 207, 158), rgb(123, 190, 192), rgb(130, 129, 180),
                    rgb(160, 103, 132), rgb(145, 70, 74), rgb(122, 55, 55));
            background-size: 2000% 2000%;
            background-repeat: no-repeat;
            animation: gradient 20s ease infinite;
        }

        @keyframes gradient {
            0% {
                background-position: 0% 50%;
            }

            50% {
                background-position: 100% 50%;
            }

            100% {
                background-position: 0% 50%;
            }
        }

        .container {
            width: 100%;
            height: 100vh;
        }

        a {
            text-decoration: none;
            color: #fff;
        }

        li {
            list-style: none;
        }

        /* NAVBAR STYLING STARTS */
        .navbar {
            display: flex;
            align-items: center;
            justify-content: space-between;
            padding: 10px;
            background-color: teal;
            color: #fff;
            border-radius: 1px;
        }

        .nav-links a {
            color: #fff;
        }

        .logo {
            display: flex;
            padding: 5px;
            margin-right: 5px;
            flex-direction: row;
            justify-content: flex-start;
            align-items: center;
        }

        .logo>img {
            width: 20%;
            margin-right: 5px;
            border-radius: 5px;
        }

        .logo>p {
            font-size: 1.2em;
        }

        .menu {
            display: flex;
            gap: 1em;
            font-size: 18px;
        }

        .menu li:hover {
            background-color: #4c9e9e;
            border-radius: 5px;
            transition: 0.3s ease;
        }

        .menu li {
            padding: 5px 14px;
        }

        /* CHECKBOX HACK */
        input[type=checkbox] {
            display: none;
        }

        /*HAMBURGER MENU*/
        .hamburger {
            display: none;
            font-size: 24px;
            user-select: none;
        }

        hr {
            margin: 10px auto 20px auto;
            width: 80%;
            background-color: #000;
            height: 2px;
            border: none;
        }

        p {
            font-family: calibri, Gill Sans, serif;
        }

        .info {
            color: white;
            font-size: 1.6rem;
            line-height: 2.3rem;
            text-align: center;
        }

        .cards {
            width: 90%;
            max-width: 600px;
            margin: 20px auto;
            padding: 15px;
            border-radius: 2px 15px 2px 15px;
            box-shadow: 0px 0px 10px 1px #000;

        }

        .color-1 {
            background-color: rgba(129, 28, 62, 0.589);
        }

        .color-2 {
            background-color: rgba(28, 129, 104, 0.733);
        }

        table {
            text-align: left;
            margin: 10px auto;
            padding: 5px;
        }

        th {
            color: rgb(244, 255, 145);
            padding: 10px;
            text-align: left;
            width: 45%;
        }

        td {
            font-size: 1.2rem;
            padding: 5px;
            /* margin: 0px 10px 0px 10px; */
            width: 45%;
            color: rgb(255, 251, 4);
        }

        .footer {
            max-width: 500px;
            width: 80%;
            margin: 5px auto;

        }

        .footer>p {
            font-size: 1rem;
            text-align: center;
            line-height: 1.7rem;
            color:white
        }

        .link {
            font-weight: bold;
        }

        .social-icons{
            display: flex;
            margin:0px auto;
            width:80%;
            max-width:200px;
            justify-content: space-evenly;
            align-items: center;
        }

        .social-icons>a>img{
            display: block;
            width:20px;
            border-radius: 40px;
            margin:1px;
        }

        .footer-container{
            margin-top: 50px;
            background-color: #000;
            margin-bottom: 50px;
        }

        @media (max-width: 768px) {
            .menu {
                display: none;
                position: absolute;
                background-color: rgba(0, 128, 128, 0.9);
                right: 0;
                text-align: center;
                padding: 16px 0;
                height: auto;
                min-width: 300px;
                overflow: auto;
            }

            .menu li:hover {
                display: inline-block;
                background-color: #4c9e9e;
                transition: 0.3s ease;
            }

            .menu li+li {
                margin-top: 12px;
            }

            input[type=checkbox]:checked~.menu {
                transition: 0.5s ease;
                display: block;
            }

            .hamburger {
                display: block;
            }

            .logo>p {
                font-size: 1em;
            }

            .info {
                font-size: 1em;
            }
        }
    </style>
</head>

<body>
    <main class="container">
        <nav class="navbar">
            <div class="logo">
                <img src="data:image/png;base64,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"
                    alt="face logo" />
                <p><a href="/">faceApp</a></p>
            </div>
            <ul class="nav-links">
                <input type="checkbox" id="checkbox_toggle" />
                <label for="checkbox_toggle" class="hamburger">&#9776;</label>
                <div class="menu">
                    <li><a href="/">Home</a></li>
                </div>
            </ul>
        </nav>
        <section class="cards color-1">
            <p class="info">
                Electronic Face Recognition Door Lock is about making your property well protected
                by adding another layer of security. Every face has its uniqueness and sometimes similarities.
                This project works by first detecting motion around the door it is installed; if motion is detected,
                it then scans for a face. if a knowwn face is detected, it automatically opens the door.
                If an unknown face is detected, it flags an intruder alarm.
            </p>
        </section>

        <section class="cards color-2">
            <p class="info">Project students are:</p>
            <table>
                <tr>
                    <th>Matric Number</th>
                    <th>Full Name</th>
                </tr>
                <tr>
                    <td>FPA/EE/20/3-0051</td>
                    <td>Olaseinde Femi</td>
                </tr>
                <tr>
                    <td>FPA/EE/20/3-0052</td>
                    <td>Olofintuyi George</td>
                </tr>
                <tr>
                    <td>FPA/EE/20/3-0053</td>
                    <td>Oluwole Jewel</td>
                </tr>
                <tr>
                    <td>FPA/EE/20/3-0054</td>
                    <td>Owoeye Kehinde</td>
                </tr>
                <tr>
                    <td>FPA/EE/20/3-0055</td>
                    <td>Oyekanmi Adeyinka</td>
                </tr>
                </tbody>
            </table>
        </section>

        <section class = "footer-container">
        <section class="footer">
            <hr>
            <p>Electronic Face Recognition Door Lock Designed and Constructed by</p>
            <p class="link"><a target="_blank" style="color:red;" href="https://g.page/r/CfQvFv81BsfaEAE">Newness
                    Electronics</a></p>
        </section>

        <section class="social-icons">
            <a target="_blank" href="https://wa.me/message/Q6NWUGR2IE5VN1"><img src="data:image/jpg;base64,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"
             alt="whatsapp"></a>
            <a target="_blank" href="https://fb.me/newnesselectronic"><img src="data:image/jpg;base64,/9j/4AAQSkZJRgABAQECowKjAAD/4QAiRXhpZgAATU0AKgAAAAgAAQESAAMAAAABAAEAAAAAAAD/7QAsUGhvdG9zaG9wIDMuMAA4QklNA+0AAAAAABACowAAAAEAAQKjAAAAAQAB/+FWV2h0dHA6Ly9ucy5hZG9iZS5jb20veGFwLzEuMC8APD94cGFja2V0IGJlZ2luPSLvu78iIGlkPSJXNU0wTXBDZWhpSHpyZVN6TlRjemtjOWQiPz4NCjx4OnhtcG1ldGEgeG1sbnM6eD0iYWRvYmU6bnM6bWV0YS8iIHg6eG1wdGs9IkFkb2JlIFhNUCBDb3JlIDUuNi1jMTQzIDc5LjE2MTIxMCwgMjAxNy8wOC8xMS0xMDoyODozNiAgICAgICAgIj4NCgk8cmRmOlJERiB4bWxuczpyZGY9Imh0dHA6Ly93d3cudzMub3JnLzE5OTkvMDIvMjItcmRmLXN5bnRheC1ucyMiPg0KCQk8cmRmOkRlc2NyaXB0aW9uIHJkZjphYm91dD0iIiB4bWxuczpkYz0iaHR0cDovL3B1cmwub3JnL2RjL2VsZW1lbnRzLzEuMS8iIHhtbG5zOnhtcD0iaHR0cDovL25zLmFkb2JlLmNvbS94YXAvMS4wLyIgeG1sbnM6eG1wR0ltZz0iaHR0cDovL25zLmFkb2JlLmNvbS94YXAvMS4wL2cvaW1nLyIgeG1sbnM6eG1wTU09Imh0dHA6Ly9ucy5hZG9iZS5jb20veGFwLzEuMC9tbS8iIHhtbG5zOnN0UmVmPSJodHRwOi8vbnMuYWRvYmUuY29tL3hhcC8xLjAvc1R5cGUvUmVzb3VyY2VSZWYjIiB4bWxuczpzdEV2dD0iaHR0cDovL25zLmFkb2JlLmNvbS94YXAvMS4wL3NUeXBlL1Jlc291cmNlRXZlbnQjIiB4bWxuczppbGx1c3RyYXRvcj0iaHR0cDovL25zLmFkb2JlLmNvbS9pbGx1c3RyYXRvci8xLjAvIiB4bWxuczpwZGY9Imh0dHA6Ly9ucy5hZG9iZS5jb20vcGRmLzEuMy8iPg0KCQkJPGRjOmZvcm1hdD5pbWFnZS9qcGVnPC9kYzpmb3JtYXQ+DQoJCQk8ZGM6dGl0bGU+DQoJCQkJPHJkZjpBbHQ+DQoJCQkJCTxyZGY6bGkgeG1sOmxhbmc9IngtZGVmYXVsdCI+RmFjZWJvb2sgTG9nbzwvcmRmOmxpPg0KCQkJCTwvcmRmOkFsdD4NCgkJCTwvZGM6dGl0bGU+DQoJCQk8eG1wOkNyZWF0b3JUb29sPkFkb2JlIElsbHVzdHJhdG9yIENDIDIyLjAgKFdpbmRvd3MpPC94bXA6Q3JlYXRvclRvb2w+DQoJCQk8eG1wOkNyZWF0ZURhdGU+MjAxOC0wMi0xOVQxNjo1NTo0MiswNzowMDwveG1wOkNyZWF0ZURhdGU+DQoJCQk8eG1wOk1vZGlmeURhdGU+MjAxOC0wMi0xOVQwOTo1NTo0Mlo8L3htcDpNb2RpZnlEYXRlPg0KCQkJPHhtcDpNZXRhZGF0YURhdGU+MjAxOC0wMi0xOVQxNjo1NTo0MiswNzowMDwveG1wOk1ldGFkYXRhRGF0ZT4NCgkJCTx4bXA6VGh1bWJuYWlscz4NCgkJCQk8cmRmOkFsdD4NCgkJCQkJPHJkZjpsaSByZGY6cGFyc2VUeXBlPSJSZXNvdXJjZSI+DQoJCQkJCQk8eG1wR0ltZzp3aWR0aD4yNTY8L3htcEdJbWc6d2lkdGg+DQoJCQkJCQk8eG1wR0ltZzpoZWlnaHQ+MjU2PC94bXBHSW1nOmhlaWdodD4NCgkJCQkJCTx4bXBHSW1nOmZvcm1hdD5KUEVHPC94bXBHSW1nOmZvcm1hdD4NCgkJCQkJCTx4bXBHSW1nOmltYWdlPi85ai80QUFRU2taSlJnQUJBZ0VDb3dLakFBRC83UUFzVUdodmRHOXphRzl3SURNdU1BQTRRa2xOQSswQUFBQUFBQkFDb3dBQUFBRUENCkFRS2pBQUFBQVFBQi8rSU1XRWxEUTE5UVVrOUdTVXhGQUFFQkFBQU1TRXhwYm04Q0VBQUFiVzUwY2xKSFFpQllXVm9nQjg0QUFnQUoNCkFBWUFNUUFBWVdOemNFMVRSbFFBQUFBQVNVVkRJSE5TUjBJQUFBQUFBQUFBQUFBQUFBQUFBUGJXQUFFQUFBQUEweTFJVUNBZ0FBQUENCkFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBUlkzQnlkQUFBQVZBQUFBQXoNClpHVnpZd0FBQVlRQUFBQnNkM1J3ZEFBQUFmQUFBQUFVWW10d2RBQUFBZ1FBQUFBVWNsaFpXZ0FBQWhnQUFBQVVaMWhaV2dBQUFpd0ENCkFBQVVZbGhaV2dBQUFrQUFBQUFVWkcxdVpBQUFBbFFBQUFCd1pHMWtaQUFBQXNRQUFBQ0lkblZsWkFBQUEwd0FBQUNHZG1sbGR3QUENCkE5UUFBQUFrYkhWdGFRQUFBL2dBQUFBVWJXVmhjd0FBQkF3QUFBQWtkR1ZqYUFBQUJEQUFBQUFNY2xSU1F3QUFCRHdBQUFnTVoxUlMNClF3QUFCRHdBQUFnTVlsUlNRd0FBQkR3QUFBZ01kR1Y0ZEFBQUFBQkRiM0I1Y21sbmFIUWdLR01wSURFNU9UZ2dTR1YzYkdWMGRDMVENCllXTnJZWEprSUVOdmJYQmhibmtBQUdSbGMyTUFBQUFBQUFBQUVuTlNSMElnU1VWRE5qRTVOall0TWk0eEFBQUFBQUFBQUFBQUFBQVMNCmMxSkhRaUJKUlVNMk1UazJOaTB5TGpFQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUENCkFBQUFBQUFBQUFBQUFGaFpXaUFBQUFBQUFBRHpVUUFCQUFBQUFSYk1XRmxhSUFBQUFBQUFBQUFBQUFBQUFBQUFBQUJZV1ZvZ0FBQUENCkFBQUFiNklBQURqMUFBQURrRmhaV2lBQUFBQUFBQUJpbVFBQXQ0VUFBQmphV0ZsYUlBQUFBQUFBQUNTZ0FBQVBoQUFBdHM5a1pYTmoNCkFBQUFBQUFBQUJaSlJVTWdhSFIwY0RvdkwzZDNkeTVwWldNdVkyZ0FBQUFBQUFBQUFBQUFBQlpKUlVNZ2FIUjBjRG92TDNkM2R5NXANClpXTXVZMmdBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBWkdWell3QUENCkFBQUFBQUF1U1VWRElEWXhPVFkyTFRJdU1TQkVaV1poZFd4MElGSkhRaUJqYjJ4dmRYSWdjM0JoWTJVZ0xTQnpVa2RDQUFBQUFBQUENCkFBQUFBQUF1U1VWRElEWXhPVFkyTFRJdU1TQkVaV1poZFd4MElGSkhRaUJqYjJ4dmRYSWdjM0JoWTJVZ0xTQnpVa2RDQUFBQUFBQUENCkFBQUFBQUFBQUFBQUFBQUFBQUFBQUdSbGMyTUFBQUFBQUFBQUxGSmxabVZ5Wlc1alpTQldhV1YzYVc1bklFTnZibVJwZEdsdmJpQnANCmJpQkpSVU0yTVRrMk5pMHlMakVBQUFBQUFBQUFBQUFBQUN4U1pXWmxjbVZ1WTJVZ1ZtbGxkMmx1WnlCRGIyNWthWFJwYjI0Z2FXNGcNClNVVkROakU1TmpZdE1pNHhBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQjJhV1YzQUFBQUFBQVRwUDRBRkY4dUFCRFANCkZBQUQ3Y3dBQkJNTEFBTmNuZ0FBQUFGWVdWb2dBQUFBQUFCTUNWWUFVQUFBQUZjZjUyMWxZWE1BQUFBQUFBQUFBUUFBQUFBQUFBQUENCkFBQUFBQUFBQUFBQUFBS1BBQUFBQW5OcFp5QUFBQUFBUTFKVUlHTjFjbllBQUFBQUFBQUVBQUFBQUFVQUNnQVBBQlFBR1FBZUFDTUENCktBQXRBRElBTndBN0FFQUFSUUJLQUU4QVZBQlpBRjRBWXdCb0FHMEFjZ0IzQUh3QWdRQ0dBSXNBa0FDVkFKb0Fud0NrQUtrQXJnQ3kNCkFMY0F2QURCQU1ZQXl3RFFBTlVBMndEZ0FPVUE2d0R3QVBZQSt3RUJBUWNCRFFFVEFSa0JId0VsQVNzQk1nRTRBVDRCUlFGTUFWSUINCldRRmdBV2NCYmdGMUFYd0Jnd0dMQVpJQm1nR2hBYWtCc1FHNUFjRUJ5UUhSQWRrQjRRSHBBZklCK2dJREFnd0NGQUlkQWlZQ0x3STQNCkFrRUNTd0pVQWwwQ1p3SnhBbm9DaEFLT0FwZ0NvZ0tzQXJZQ3dRTExBdFVDNEFMckF2VURBQU1MQXhZRElRTXRBemdEUXdOUEExb0QNClpnTnlBMzREaWdPV0E2SURyZ082QThjRDB3UGdBK3dEK1FRR0JCTUVJQVF0QkRzRVNBUlZCR01FY1FSK0JJd0VtZ1NvQkxZRXhBVFQNCkJPRUU4QVQrQlEwRkhBVXJCVG9GU1FWWUJXY0Zkd1dHQlpZRnBnVzFCY1VGMVFYbEJmWUdCZ1lXQmljR053WklCbGtHYWdaN0Jvd0cNCm5RYXZCc0FHMFFiakJ2VUhCd2NaQnlzSFBRZFBCMkVIZEFlR0I1a0hyQWUvQjlJSDVRZjRDQXNJSHdneUNFWUlXZ2h1Q0lJSWxnaXENCkNMNEkwZ2puQ1BzSkVBa2xDVG9KVHdsa0NYa0pqd21rQ2JvSnp3bmxDZnNLRVFvbkNqMEtWQXBxQ29FS21BcXVDc1VLM0FyekN3c0wNCklnczVDMUVMYVF1QUM1Z0xzQXZJQytFTCtRd1NEQ29NUXd4Y0RIVU1qZ3luRE1BTTJRenpEUTBOSmcxQURWb05kQTJPRGFrTnd3M2UNCkRmZ09FdzR1RGtrT1pBNS9EcHNPdGc3U0R1NFBDUThsRDBFUFhnOTZENVlQc3cvUEQrd1FDUkFtRUVNUVlSQitFSnNRdVJEWEVQVVINCkV4RXhFVThSYlJHTUVhb1J5UkhvRWdjU0poSkZFbVFTaEJLakVzTVM0eE1ERXlNVFF4TmpFNE1UcEJQRkUrVVVCaFFuRkVrVWFoU0wNCkZLMFV6aFR3RlJJVk5CVldGWGdWbXhXOUZlQVdBeFltRmtrV2JCYVBGcklXMWhiNkZ4MFhRUmRsRjRrWHJoZlNGL2NZR3hoQUdHVVkNCmloaXZHTlVZK2hrZ0dVVVpheG1SR2JjWjNSb0VHaW9hVVJwM0dwNGF4UnJzR3hRYk94dGpHNG9ic2h2YUhBSWNLaHhTSEhzY294ek0NCkhQVWRIaDFISFhBZG1SM0RIZXdlRmg1QUhtb2VsQjYrSHVrZkV4OCtIMmtmbEIrL0grb2dGU0JCSUd3Z21DREVJUEFoSENGSUlYVWgNCm9TSE9JZnNpSnlKVklvSWlyeUxkSXdvak9DTm1JNVFqd2lQd0pCOGtUU1I4SktzazJpVUpKVGdsYUNXWEpjY2w5eVluSmxjbWh5YTMNCkp1Z25HQ2RKSjNvbnF5ZmNLQTBvUHloeEtLSW8xQ2tHS1RncGF5bWRLZEFxQWlvMUttZ3FteXJQS3dJck5pdHBLNTByMFN3RkxEa3MNCmJpeWlMTmN0REMxQkxYWXRxeTNoTGhZdVRDNkNMcmN1N2k4a0wxb3ZrUy9ITC80d05UQnNNS1F3MnpFU01Vb3hnakc2TWZJeUtqSmoNCk1wc3kxRE1OTTBZemZ6TzRNL0UwS3pSbE5KNDAyRFVUTlUwMWh6WENOZjAyTnpaeU5xNDI2VGNrTjJBM25EZlhPQlE0VURpTU9NZzUNCkJUbENPWDg1dkRuNU9qWTZkRHF5T3U4N0xUdHJPNm83NkR3blBHVThwRHpqUFNJOVlUMmhQZUErSUQ1Z1BxQSs0RDhoUDJFL29qL2kNClFDTkFaRUNtUU9kQktVRnFRYXhCN2tJd1FuSkN0VUwzUXpwRGZVUEFSQU5FUjBTS1JNNUZFa1ZWUlpwRjNrWWlSbWRHcTBid1J6VkgNCmUwZkFTQVZJUzBpUlNOZEpIVWxqU2FsSjhFbzNTbjFLeEVzTVMxTkxta3ZpVENwTWNreTZUUUpOU2syVFRkeE9KVTV1VHJkUEFFOUoNClQ1TlAzVkFuVUhGUXUxRUdVVkJSbTFIbVVqRlNmRkxIVXhOVFgxT3FVL1pVUWxTUFZOdFZLRlYxVmNKV0QxWmNWcWxXOTFkRVY1SlgNCjRGZ3ZXSDFZeTFrYVdXbFp1Rm9IV2xaYXBscjFXMFZibFZ2bFhEVmNobHpXWFNkZGVGM0pYaHBlYkY2OVh3OWZZVit6WUFWZ1YyQ3ENCllQeGhUMkdpWWZWaVNXS2NZdkJqUTJPWFkrdGtRR1NVWk9sbFBXV1NaZWRtUFdhU1p1aG5QV2VUWitsb1AyaVdhT3hwUTJtYWFmRnENClNHcWZhdmRyVDJ1bmEvOXNWMnl2YlFodFlHMjViaEp1YTI3RWJ4NXZlRy9SY0N0d2huRGdjVHB4bFhId2NrdHlwbk1CYzExenVIUVUNCmRIQjB6SFVvZFlWMTRYWStkcHQyK0hkV2Q3TjRFWGh1ZU14NUtubUplZWQ2Um5xbGV3UjdZM3ZDZkNGOGdYemhmVUY5b1g0QmZtSisNCnduOGpmNFIvNVlCSGdLaUJDb0ZyZ2MyQ01JS1NndlNEVjRPNmhCMkVnSVRqaFVlRnE0WU9obktHMTRjN2g1K0lCSWhwaU02Sk00bVoNCmlmNktaSXJLaXpDTGxvdjhqR09NeW8weGpaaU4vNDVtanM2UE5vK2VrQWFRYnBEV2tUK1JxSklSa25xUzQ1Tk5rN2FVSUpTS2xQU1YNClg1WEpsalNXbjVjS2wzV1g0SmhNbUxpWkpKbVFtZnlhYUpyVm0wS2JyNXdjbkltYzk1MWtuZEtlUUo2dW54MmZpNS82b0dtZzJLRkgNCm9iYWlKcUtXb3dhamRxUG1wRmFreDZVNHBhbW1HcWFMcHYybmJxZmdxRktveEtrM3FhbXFIS3FQcXdLcmRhdnByRnlzMEsxRXJiaXUNCkxhNmhyeGF2aTdBQXNIV3c2ckZnc2RheVM3TENzeml6cnJRbHRKeTFFN1dLdGdHMmViYnd0MmkzNExoWnVORzVTcm5DdWp1NnRic3UNCnU2ZThJYnlidlJXOWo3NEt2b1MrLzc5NnYvWEFjTURzd1dmQjQ4SmZ3dHZEV01QVXhGSEV6c1ZMeGNqR1JzYkR4MEhIdjhnOXlMekoNCk9zbTV5ampLdDhzMnk3Yk1OY3kxelRYTnRjNDJ6cmJQTjgrNDBEblF1dEU4MGI3U1A5TEIwMFRUeHRSSjFNdlZUdFhSMWxYVzJOZGMNCjErRFlaTmpvMld6WjhkcDIydnZiZ053RjNJcmRFTjJXM2h6ZW90OHAzNi9nTnVDOTRVVGh6T0pUNHR2alkrUHI1SFBrL09XRTVnM20NCmx1Y2Y1Nm5vTXVpODZVYnAwT3BiNnVYcmNPdjc3SWJ0RWUyYzdpanV0TzlBNzh6d1dQRGw4WEx4Ly9LTTh4bnpwL1EwOU1MMVVQWGUNCjltMzIrL2VLK0JuNHFQazQrY2Y2Vi9ybiszZjhCL3lZL1NuOXV2NUwvdHovYmYvLy8rNEFEa0ZrYjJKbEFHVEFBQUFBQWYvYkFJUUENCkJnUUVCQVVFQmdVRkJna0dCUVlKQ3dnR0JnZ0xEQW9LQ3dvS0RCQU1EQXdNREF3UURBNFBFQThPREJNVEZCUVRFeHdiR3hzY0h4OGYNCkh4OGZIeDhmSHdFSEJ3Y05EQTBZRUJBWUdoVVJGUm9mSHg4Zkh4OGZIeDhmSHg4Zkh4OGZIeDhmSHg4Zkh4OGZIeDhmSHg4Zkh4OGYNCkh4OGZIeDhmSHg4Zkh4OGZIeDhmLzhBQUVRZ0JBQUVBQXdFUkFBSVJBUU1SQWYvRUFhSUFBQUFIQVFFQkFRRUFBQUFBQUFBQUFBUUYNCkF3SUdBUUFIQ0FrS0N3RUFBZ0lEQVFFQkFRRUFBQUFBQUFBQUFRQUNBd1FGQmdjSUNRb0xFQUFDQVFNREFnUUNCZ2NEQkFJR0FuTUINCkFnTVJCQUFGSVJJeFFWRUdFMkVpY1lFVU1wR2hCeFd4UWlQQlV0SGhNeFppOENSeWd2RWxRelJUa3FLeVkzUENOVVFuazZPek5oZFUNClpIVEQwdUlJSm9NSkNoZ1poSlJGUnFTMFZ0TlZLQnJ5NC9QRTFPVDBaWFdGbGFXMXhkWGw5V1oyaHBhbXRzYlc1dlkzUjFkbmQ0ZVgNCnA3ZkgxK2YzT0VoWWFIaUltS2k0eU5qbytDazVTVmxwZVltWnFibkoyZW41S2pwS1dtcDZpcHFxdXNyYTZ2b1JBQUlDQVFJREJRVUUNCkJRWUVDQU1EYlFFQUFoRURCQ0VTTVVFRlVSTmhJZ1p4Z1pFeW9iSHdGTUhSNFNOQ0ZWSmljdkV6SkRSRGdoYVNVeVdpWTdMQ0IzUFMNCk5lSkVneGRVa3dnSkNoZ1pKalpGR2lka2RGVTM4cU96d3lncDArUHpoSlNrdE1UVTVQUmxkWVdWcGJYRjFlWDFSbFptZG9hV3ByYkcNCjF1YjJSMWRuZDRlWHA3ZkgxK2YzT0VoWWFIaUltS2k0eU5qbytEbEpXV2w1aVptcHVjblo2ZmtxT2twYWFucUttcXE2eXRycSt2L2ENCkFBd0RBUUFDRVFNUkFEOEE5VTRxN0ZYWXE3RlhZcTdGWFlxN0ZYWXE3RlV2MWp6RG9laXdldHF0OUJaUm5kZldjS3pVL2xYN1RmUU0NCm5ESEtYSVd4bElEbTg4MXovbklYeW5abGswdTJ1TlVrSFI2ZlY0ai9BTEp3WC80VE15SFo4enoyYVphbUk1TUYxWC9uSVh6bGRGbHMNCkxlMTArUDhBWklRelNENXM1NEgvQUlETXVIWjhCenN0SjFNdWpGci9BUE0vOHdMNG4xOWR1bHIxRURDM0gvSkVSNWtSMHVNZndock8NCldSNnBIY2ExckZ5YTNOOWNUbnhrbGQrMVAyaWN0RUlqa0dCa1VIa2tPeFZHVyt0YXhiR3R0ZlhFQjhZNVhUdFQ5a2pJbUVUekNSSXANCjVZZm1mK1lGaVI2R3UzVFU2Q2RoY0Qva3NKTXFscGNaL2hETVpaRHF5blN2K2NoZk9WcVZXL3Q3WFVJLzJpVU1NaCtUSWVBLzRETWUNCmZaOER5c05nMU11ck90RC9BT2NoZktkNFZUVkxhNDB1UTlYcDlZaUgreVFCL3dEaE14SjluekhMZHVqcVlubTlEMGZ6RG9ldFFldHANClY5QmV4amR2UmNNeTEvbVg3Uy9TTXc1NDVSNWltNk1nZVNZWkJrN0ZYWXE3RlhZcTdGWFlxN0ZYWXE3RlhZcTdGWFlxN0ZYWXE3RlgNCllxN0ZXTStidnpGOHErVm96K2tyb1BkMHFsaEJTU2R1NCtHbzRqM1lnWmZoMDg4bkliTmM4c1k4M2kvbXI4L1BOT3BsNE5IVmRJdEQNCnNIV2tsd3c5NUdIRmY5aXRmZk5uaTBFSS9WdVhGbnFDZVd6elc3dkx1OHVIdUx1ZVM0dUpEV1NhVm1kMlB1ekVrNW5BQUNnNDVOcU8NCkZYWXE3RlhZcTdGWFlxN0ZYWXE3RlhZcXJXbDVkMmR3bHhhVHlXOXhHYXh6Uk15T3A5bVVnakFRQ0tLZzA5SzhxL241NXAwd3BCckMNCnJxOW9OaTdVanVGSHRJbzR0L3Nscjc1ZzVkQkNYMDdGeUlhZ2pudTlvOG8vbUw1VjgweGo5RzNRUzdwVjdDZWtjNjl6OE5UeUh1cEkNCnpXWnRQUEh6R3psUXl4bHlaTmxEWTdGWFlxN0ZYWXE3RlhZcTdGWFlxN0ZYWXE3RlhZcTdGVUxxbXE2YnBWakxmYWpjSmEya0lySk4NCklhQWV3OFNld0c1eVVZR1JvYzBFZ0N5OEo4OS9uM3FWOFpMSHl3R3NiUGRXdjNIK2tPUDhnZEl4L3dBTjhzMjJEUUFiejNMaDVOUVQNCnNIa2tzc3MwclN5dTBrcmtzOGprc3pFOVNTZHpteEFweGxtS3V4VjJLdXhWMkt1eFYyS3V4VjJLdXhWMkt1eFYyS3V4VmZGTExES3MNCnNUdEhLaERKSWhLc3BIUWdqY1lrV3IxdnlKK2ZlcFdKanNmTTRhK3M5bFcvUWY2UWcveXgwa0gvQUEzenpYWjlBRHZEWXVUajFCR3gNCmU3YVhxdW02cll4WDJuWENYVnBNS3h6Um1vUHNmQWp1RHVNMU1vR0pvODNNQkJGaEZaRkxzVmRpcnNWZGlyc1ZkaXJzVmRpcnNWZGkNCnJHL08vbjNSUEtHbmZXYjkvVXVwQWZxbGloSHF5c1ArSXFPN0hwN25iTDhHQ1dRMEd2SmtFUnUrWnZPWG5yWHZObCtiblVwYVFJVDkNCldzb3lSREVQOGxlN2VMSGZONWh3UnhpZzRFOGhrZDJQWmN3ZGlyc1ZkaXJzVmRpcnNWZGlyc1ZkaXJzVmRpcnNWZGlyc1ZkaXJzVmQNCmlySWZKdm5yWHZLZCtMblRaYXdPUjlac3BDVERLUDhBS1hzM2d3M3luTmdqa0ZGbkRJWW5aOU0rU1BQdWgrYnRPK3MyRCtuZFJnZlcNCjdGeVBVaVkvOFNVOW1IWDU3Wm84K0NXTTBYUHg1QkliTWt5aHNkaXJzVmRpcnNWZGlyc1ZkaXJzVllmK1kzNWphZDVOMDVXWlJjNnINCmNnL1U3T3RLMDJNa2hIUkIrUFFkeU1uVGFZNUQ1TldYS0lqemZNR3VhNXFtdWFuTnFXcHp0Y1hjNXF6dDBBN0tvNktvN0FadllRRVINClE1T3ZsSWsyVUJrME94VjJLdXhWMkt1eFYyS3V4VjJLdXhWc0FrZ0FWSjZERldRYWIrWDNuZlVsRDJlaVhieHR1c2p4bU5EOG1rNHENCmZ2eW1Xb3h4NWtNeGprZWliRDhsZnpOSXIraHV2L0x6YS84QVZYSy96dUx2K3dzdkFuM04vd0RLbFB6Ti93Q3JOLzA4Mm4vVlhIODcNCmk3L3NLK0JQdVE4MzVSZm1QRUdMYUpLZU94NFBDLzNjWE5mb3dqVjR1OUhnejdrczFEeUw1eTA2R1NlODBXOGlnaUJhV1l3dVkxVUMNCnBablVGUUI0MXl5T2VFdVJDRGprT2lSWmF3ZGlyc1ZkaXFQMFBYTlUwUFU0ZFMweWRyZTdnTlZkZWhIZFdIUmxQY0hJVGdKQ2p5VEcNClJCc1BwLzhBTG44eHRPODVhY3pLb3R0VnRnUHJsbld0SzdDU01ucWgvRG9leE9pMU9tT00rVHNNV1VTSG16RE1adGRpcnNWZGlyc1YNCmRpcnNWWTM1OTg3NmQ1UjBONys1cEpkU1ZTeHRLMGFXU240S3ZWajIrZE12d1lEa2xRYThtUVJGdmxUWE5jMVBYTlVuMVBVcGpQZDMNCkRjblk5QU95cU95cU5nTTM4SUNJb2NuWFNrU2JLQXlhSFlxN0ZYWXE3RlhZcTdGWFlxN0ZYWXE5RC9MejhuZFk4MExIcUY2eDAvUlcNCjNXY2lzc3dIKytsUGIvS08zaFhNUFVheU9QWWJ5YnNlQXkzNlBldkxQa0R5bjVialVhWllScmNMMXZKUUpKeWZIMUczSHlXZ3pVWmQNClJPZk11YkRIR1BKa09VczNZcTdGWFlxeDM4eHYrVUQxL3dENWdaLytJSEx0Ti9lUjk3REw5SmZJZWRHNngyS3V4VjJLdXhWSDZIcm0NCnA2SHFrR3A2Yk1ZTHUzYmtqRG9SM1ZoM1Zoc1JrSndFaFI1SmpJZzJIMVg1Qzg3NmQ1dTBOTCsycEhkUjBTK3RLMWFLU240cTNWVDMNCitkYzBHZkFjY3FMc2NlUVNGc2t5aHNkaXJzVmRpcnNWUXVxNnBZNlZwdHhxTjlLSWJTMVF5VFNIc0IySGlUMEE3bkpRaVpHaHpRU0ENCkxMNU04OWVjci96WnIwdXBYSktRQ3NkbGJWMmloQitGZjlZOVdQam5RNE1JeHhvT3R5VE1qYkhzdVlPeFYyS3V4VjJLdXhWMkt1eFYNCjJLdXhWNlQrVGY1YnI1bTFKdFUxS091aVdEZ0ZEMG5tRkdFZitxb29YK2dkOHd0WnFlQVVQcUxmZ3hjUnM4bjBvaUlpS2lLRlJRQXENCmdVQUE2QURORzU3ZUt1eFYyS3V4VjJLc2QvTWIvbEE5Zi81Z1ovOEFpQnk3VGYza2Zld3kvU1h5SG5SdXNkaXJzVmRpcnNWZGlySWYNCkl2bksvd0RLZXZSYWxiRXZBYVIzdHRYYVdFbjRsLzFoMVUrT1U1OEl5Um9zOGN6RTIrczlLMVN4MVhUYmZVYkdVVFdsMGdraGtIY0gNCnNmQWpvUjJPYzlPSmlhUE4yUUlJc0lySXBkaXJzVmRpcjUvL0FENzg5bSsxSWVXTEdUL1E3Rmc5K3luWjdqc255akgvQUEzeXpjYUQNCkJRNHp6TGhhakpab1BJYzJMak94VjJLdXhWMkt1eFYyS3V4VjJLdXhWVnRyZWE1dVlyYUJESlBPNnh4UmpxenVlS2dmTW5BVFF0UUgNCjJINVU4dlczbDd5OVk2UGIwNDJzWVdSeCszSWZpa2YvQUdUa25PYnk1RE9Sa1hhUWp3aWsyeXRrN0ZYWXE3RlhZcTdGV08vbU4veWcNCmV2OEEvTURQL3dBUU9YYWIrOGo3MkdYNlMrUTg2TjFqc1ZkaXJzVmRpcnNWZGlyMTc4aFBQWnNkU1BsaStrLzBPK1l2WU14MlM0N3ANCjhwQi93M3p6WGEvQlk0eHpEazZmSlJvdm9ETk81cnNWZGlyR2Z6RjgzUitWdkt0MXFWUjliY2VoWUlmMnA1QWVPeDdMUXNmWVpmcDgNClBpVEE2TmVXZkRHM3lWTExMTks4c3JGNVpHTHlPeHFXWmpVa24zT2RFQlRyVm1LdXhWMkt1eFYyS3V4VjJLdXhWMkt1eFZtMzVONlUNCnVvL21IcGF1dktLMUwzYit4aFFzaC81R2NjeGRaUGh4bHR3QzVCOVVab0hZdXhWMkt1eFZodm5IODEvS2ZsYWMybDNLOTFxQ2dGck8NCjJBZDFydVBVWWxWWDVWcjdaazRkSlBKdU9UVlBOR0xCcHY4QW5KYUFPUkQ1ZVo0K3pQZGhEOXdoZjllWlk3Ti9wZlkwL212SlQvNkcNClgvNzl6L3A5L3dDemZEL0puOUw3UDJyK2E4a3U4eC9uL3dEcG5RYi9BRW45QStoOWVnZUQxdnJmUGh6V25MajZLMXA4OG5qN1A0WkENCjhYTHkvYXhscWJGVThoell1TTdGWFlxN0ZYWXE3RlhZcXZpbGxobFNXSmlrc2JCNDNVMEtzcHFDRDdIRWkxZld2NWRlYm8vTlBsVzENCjFLbyt0b1BRdjBIN004WUhMWWRtcUdIc2M1M1VZZkRtUjBkbGlueFJ0azJVTmpzVmZPSDUrZWFqcWZtbE5IaGF0cG82OEhwMGE0a0ENCmFRLzdFY1YrWU9iclFZdUdIRjFMZzZpZG11NTVobWU0N3NWZGlyc1ZkaXJzVmRpcnNWZGlyc1ZkaXIxWC9uSFNBUDV4dnBqVDkxcDcNCmdEM2FhTGY3Z2MxL2FKOUE5N2thYjZuMFRtbWM1Mkt1eFZKL09HdHRvZmxmVTlWU25xMmx1N3cxNmVxUnhqci9BTE1qTE1NT09ZREcNCmNxQkw0OXVKNTdpZVM0bmRwWjVXTHl5TWFzek1ha2tudVRuU0FWczZzbFR3cTdGWFlxN0ZYWXE3RlhZcTdGWFlxN0ZYWXE5US9JUHoNClVkTTgwdG84NzB0TlhYaWdQUmJpTUZvei9zbDVMODZaZ2EvRnhRNHVvY2pUem8xM3ZvN05LNXlYK1lkWWcwWFE3N1ZadDQ3S0I1dUoNCjI1TW8rRmY5azFCazhjT0tRSGV4bEtoYjQzdkx1NHZMdWU3dUhNbHhjU05MTkllck83Rm1QMGs1MG9BQW9Pckp0UndxN0ZYWXE3RlgNCllxN0ZYWXE3RlhZcTdGWFlxOWEvNXh4LzVTblUvd0RtQi81bkptdTdTK2dlOXlkTHpMNkV6VHVhN0ZYWXF3bjg2V1pmeXoxa3FhR2wNCnVLandOMUVEK0daV2kvdlIrT2pWbitndmxmTis2NTJLdXhWMkt1eFYyS3V4VjJLdXhWMkt1eFYyS3ExbmQzRm5kd1hkdTVqdUxlUloNCllaQjFWMFlNcCtnakFRQ0tLZzAreVBMMnNRYTFvZGpxc08wZDdBazNFYjhXWWZFdit4YW96bXNrT0dSSGM3U01yRnZQUCtjaGRjTm4NCjVUdHRMUnFTYXBjRG1QR0szbzdmOE9Vek03UGhjNzdtblV5cU5QblROMDRMc1ZkaXJzVmRpcnNWZGlyc1ZkaXJzVmRpcnNWZXRmOEENCk9PUC9BQ2xPcC84QU1EL3pPVE5kMmw5QTk3azZYbVgwSm1uYzEyS3V4VmhINTEvK1N5MW4vbzIvNmk0c3l0Ri9lajQvYzA1L29MNVkNCnpmdXZkaXJzVmRpcnNWZGlyc1ZkaXJzVmRpcnNWZGlyc1ZmUmYvT1BXdUc4OHAzT2x1MVpOTHVEd0hoRmNWZGYrSEQ1cGUwSVZPKzkNCnp0Tks0MHdYL25JWFZUZGVjcmV3VnYzZW4ycUFyNFNURXV4K2xPR1pmWjhLaGZlV25VbjFVOHV6UGNkMkt1eFYyS3V4VjJLdXhWMksNCnV4VldXenUyVU1zRWpLZHdRakVFZmRnc0xUZjFHKy81WjVmK0FiK21QRUZvdStvMzMvTFBML3dEZjB4NGd0RjZ4L3pqcmJYRVhtalUNCmpMRTZBMlZBV1VnVjlWUEhOZjJpUndEM3VUcGh1WHYrYWR6WFlxN0ZXRmZuUEc4bjVhYXdpS1hjL1ZxS29xVC9BS1ZGMkdaV2kvdlINCjhmdWFzLzBGOHUvVWI3L2xubC80QnY2WnZ1SU91b3UrbzMzL0FDenkvd0RBTi9USGlDMFhmVWI3L2xubC93Q0FiK21QRUZvclpMVzYNCmpYbEpDNktPck1wQSs4akd3dEtXRlhZcTdGWFlxN0ZYWXE3RlhZcTdGWHFQL09QV3FtMTg1WEZnemZ1OVF0WEFYeGtoSWRUOUNjOHcNCk8wSVhDKzR1UnBqNnFZdCtaOStiNzh3TmRuclhqZE5BRDdXNEVQOEF6THpJMHNheHg5elhsTnlMRjh2YTNZcTdGWFlxN0ZYWXE3RlgNCllxN0ZYMTUrWFA4QXlnZWdmOHdNSC9FQm5PYW4rOGw3M1o0dnBESXNwWnV4VjJLdXhWMkt1eFYyS3V4VjJLdXhWNW4vQU01QjN2b2UNClJJNEFkN3U5aWpJL3lWVjVQMW9NenV6NDNrOXdjZlVuMHZtM04yNExzVmRpcnNWZGlyc1ZkaXJzVmRpcktQeXd2elkvbUJvVTlhY3INCnBZQ2ZhNEJoL3dDWm1VYXFONDVlNXN4R3BCSTlhdURjNnhmWEo2ejNFc2g2ZnR1VzdmUExZQ29nTUpIZEI1SkRzVmRpcnNWZGlyc1YNCmRpcnNWZGlyNjgvTG4vbEE5QS81Z1lQK0lET2MxUDhBZVM5N3M4WDBoa1dVczNZcTdGWFlxN0ZYWXE3RlhZcTdGWFlxOFcvNXlVdmUNCk5wb1ZrRC9lU1hFekQvakdxS3YvQUJNNXMrelk3eUxpYW84bmhXYlp4SFlxN0ZYWXE3RlhZcTdGWFlxN0ZVWm90d2JiV0xHNUhXQzQNCmlrSFQ5aHczZjVaR1l1SkNZbmRCNUpEc1ZkaXJzVmRpcnNWZGlyc1ZkaXJzVmZYbjVjLzhvSG9IL01EQi93QVFHYzVxZjd5WHZkbmkNCitrTWl5bG03RlhZcTdGWFlxN0ZYWXE3RlhZcTdGWHp6L3dBNUdYbnFlYTlQdEFhcmIyUWMrelN5dlg4RUdibnM2UG9KODNDMUo5VHkNCmZOZzR6c1ZkaXJzVmRpcnNWZGlyc1ZkaXJzVmRpcnNWZGlyc1ZkaXJzVmRpcnNWZGlyc1ZmWG41Yy84QUtCNkIvd0F3TUgvRUJuT2ENCm4rOGw3M1o0dnBESXNwWnV4VjJLdXhWMkt1eFYyS3V4VjJLdXhWOHUvbmRlZldmekgxSlJ1dHNrRUtuNVFxeC80WnptKzBNYXhCMSsNCmMrc3NEekxhWFlxN0ZYWXE3RlhZcTdGWFlxN0ZYWXFqTmF0emJheGZXeDZ3WEVzWjZmc09WN2ZMSXdOeEJUSWJvUEpJZGlyc1ZkaXINCnNWZGlyc1ZkaXJzVmRpcnNWZGlyMXIvbkhIL2xLZFQvQU9ZSC9tY21hN3RMNkI3M0owdk12b1ROTzVyc1ZkaXJDUHpyL3dESlphei8NCkFORzMvVVhGbVZvdjcwZkg3bW5QOUJmTEdiOTE3c1ZkaXJzVmRpcnNWZGlyc1ZkaXJzVmRpcnNWZGlxTTBXM056ckZqYkRyUGNSUmoNCnArMjRYdjhBUEl6TlJKVEVicDUrWjlnYkg4d05kZ3BUbGROT0I3WEFFMy9Nekt0TEs4Y2ZjenlpcEZpK1h0YnNWZGlyc1ZkaXJzVmQNCmlyc1ZkaXJzVmRpcnNWZXRmODQ0L3dES1U2bi9BTXdQL001TTEzYVgwRDN1VHBlWmZRbWFkelhZcTdGV0Vmblgvd0NTeTFuL0FLTnYNCitvdUxNclJmM28rUDNOT2Y2QytXTTM3cjNZcTdGWFlxN0ZYWXE3RlhZcTdGWFlxN0ZYWXE3RldVZmxoWUcrL01EUW9LVjQzU3prZTENCnVETi96THlqVlNySEwzTm1JWElNcC81eUYwbzJ2bkszdjFYOTNxRnFoTGVNa0pLTVBvVGhtUDJmTzRWM0ZzMUk5VnZMc3ozSGRpcnMNClZkaXJzVmRpcnNWZGlyc1ZkaXJzVmRpcjFyL25ISC9sS2RUL0FPWUgvbWNtYTd0TDZCNzNKMHZNdm9UTk81cnNWZGlyQ1B6ci93REoNClphei9BTkczL1VYRm1Wb3Y3MGZIN21uUDlCZkxHYjkxN3NWZGlyc1ZkaXJzVmRpcnNWZGlyc1ZkaXJzVmRpcjFIL25IclNqZGVjcmkNCi9aZjNlbjJya040U1RFSW8rbE9lWUhhRTZoWGVYSTB3OVZzNi93Q2NoZERONTVUdHRVUmF5YVhjRG1mQ0s0b2pmOE9FekU3UG5VNjcNCjI3VXh1TnZuVE4wNExzVmRpcnNWZGlyc1ZkaXJzVmRpcnNWZGlyc1ZldGY4NDQvOHBUcWYvTUQvQU16a3pYZHBmUVBlNU9sNWw5Q1oNCnAzTmRpcnNWWVIrZGYva3N0Wi82TnY4QXFMaXpLMFg5NlBqOXpUbitndmxqTis2OTJLdXhWMkt1eFYyS3V4VjJLdXhWMkt1eFYyS3UNCnhWOUYvd0RPUFdobXo4cDNPcU90Sk5VdUR3UGpGYjFSZitITDVwZTBKM091NXp0TkdvMjlEOHc2UEJyV2gzMmxUYlIzc0R3OGp2eFoNCmg4TGY3RnFITVBIUGhrRDNOMG8yS2ZHOTVhWEZuZHoybHdoanVMZVJvcG96MVYwWXF3K2dqT2xCQkZoMVpGS09GWFlxN0ZYWXE3RlgNCllxN0ZYWXE3RlhZcTdGWHJYL09PUC9LVTZuL3pBLzhBTTVNMTNhWDBEM3VUcGVaZlFtYWR6WFlxN0ZXRWZuWC9BT1N5MW4vbzIvNmkNCjRzeXRGL2VqNC9jMDUvb0w1WXpmdXZkaXJzVmRpcnNWZGlyc1ZkaXJzVmRpcnNWZGlxdFoybHhlWGNGcGJvWkxpNGtXS0dNZFdkMkMNCnFQcEp3RWdDeW9GdnNqeTlvOEdpNkhZNlZEdkhaUUpEeUczSmxIeE4vc21xYzVySlBpa1QzdTBqR2hTWVpCaytjZno4OHFuVFBOSzYNCnhBbExUVjE1T1IwVzRqQVdRZjdKZUxmT3ViclFaZUtIRDFEZzZpRkcrOTVmbWU0N3NWZGlyc1ZkaXJzVmRpcnNWZGlyc1ZkaXIxci8NCkFKeHgvd0NVcDFQL0FKZ2YrWnlacnUwdm9IdmNuUzh5K2hNMDdtdXhWMktzSS9Pdi93QWxsclAvQUViZjlSY1daV2kvdlI4ZnVhYy8NCjBGOHNadjNYdXhWMkt1eFYyS3V4VjJLdXhWMkt1eFYyS3V4VjZoK1FmbFU2bjVwYldKMHJhYVF2SkNlalhFZ0t4ai9ZcnliNTB6QTENCitYaGh3OVM1R25oWnZ1ZlIyYVZ6bllxeG44eGZLTWZtbnlyZGFiUWZXMEhyMkRuOW1lTUhqdWV6VktuMk9YNmZONGN3ZWpYbGh4UnANCjhsU3hTd3l2RktwU1dOaWtpTUtGV1UwSUk5am5SQTI2MVppcnNWZGlyc1ZkaXJzVmRpcnNWZGlyc1ZldGY4NDQvd0RLVTZuL0FNd1ANCi9NNU0xM2FYMEQzdVRwZVpmUW1hZHpYWXE3RldFZm5YL3dDU3kxbi9BS052K291TE1yUmYzbytQM05PZjZDK1dNMzdyM1lxN0ZYWXENCjdGWFlxN0ZYWXE3RlhZcTdGVjhVVXMwcVJSS1hsa1lKR2lpcFptTkFBUGM0azByNjIvTHJ5bEY1VzhxMnVtMEgxdHg2OSs0L2FuY0QNCmx2NExRS1BZWnp1b3plSk1ubzdMRkRoalRKY29iSFlxN0ZYei93RG4zNUVOanFROHoyTWYraDN6Qkw5Vkd5WEhaL2xJUCtHK2VialENClo3SEFlWWNMVVk2Tmg1RG14Y1oyS3V4VjJLdXhWMkt1eFYyS3V4VjJLdld2K2NjZitVcDFQL21CL3dDWnlacnUwdm9IdmNuUzh5K2gNCk0wN211eFYyS3NJL092OEE4bGxyUC9SdC93QlJjV1pXaS92UjhmdWFjLzBGOHNadjNYdXhWMkt1eFYyS3V4VjJLdXhWMkt1eFYyS3YNClh2eUU4aUcrMUkrWjc2UC9BRU94WXBZS3cyZTQ3djhBS01mOE44czEydnowT0FjeTVPbngyYkw2QXpUdWE3RlhZcTdGVUxxdWwyT3ENCjZiY2FkZlJDYTB1a01jMFo3Zzl4NEVkUWV4eVVKR0pzYzBFQWlpK1RQUFhrMi84QUtldlM2YmNndkFheVdWelRhV0VuNFcvMWgwWWUNCk9kRGd6REpHdzYzSkF4Tk1leTVnN0ZYWXE3RlhZcTdGWFlxN0ZYWXE5YS81eHgvNVNuVS8rWUgvQUpuSm11N1MrZ2U5eWRMekw2RXoNClR1YTdGWFlxd2o4Ni93RHlXV3MvOUczL0FGRnhabGFMKzlIeCs1cHovUVh5eG0vZGU3RlhZcTdGWFlxN0ZYWXE3RlhZcTdGV1JlUmYNCkp0LzVzMStIVGJlcVFDa2w3YzBxSW9RZmliL1dQUlI0NVRuekRIR3l6eHdNalQ2eTByUzdIU3ROdDlPc1loRGFXcUNPR01kZ081OFMNCmVwUGM1ejA1R1JzODNaQUFDZ2lzaWwyS3V4VjJLdXhWamZuM3lScDNtN1Ezc0xta2QxSFY3RzdwVm9wS2ZpcmRHSGY1MHkvQm5PT1YNCmhyeVl4SVUrVk5jMFBVOUQxU2ZUTlNoTUYzYnR4ZFQwSTdNcDdxdzNCemZ3bUpDeHlkZEtKQm9vREpvZGlyc1ZkaXJzVmRpcnNWZGkNCnIxci9BSnh4L3dDVXAxUC9BSmdmK1p5WnJ1MHZvSHZjblM4eStoTTA3bXV4VjJLc0kvT3Yvd0FsbHJQL0FFYmY5UmNXWldpL3ZSOGYNCnVhYy8wRjhzWnYzWHV4VjJLdXhWMkt1eFYyS3V4VjJLby9ROUQxUFhOVWcwelRZVFBkM0RjVVVkQU83TWV5cU55Y2hPWWlMUEpNWWsNCm1nK3EvSVhralR2S09ocFlXMUpMcVNqMzEzU2pTeVUvQlY2S08zenJtZ3o1emtsWmRqanhpSXBrbVVOanNWZGlyc1ZkaXJzVmRpckQNCi93QXh2eTUwN3pscHlxekMyMVcyQitwM2xLMHJ1WTVBT3FIOE9vN2c1T20xSnhueWFzdUlTSG0rWU5jMFBWTkQxT2JUZFRnYTN1NEQNClJrYm9SMlpUMFpUMkl6ZXdtSkN4eWRmS0pCb29ESm9kaXJzVmRpcnNWZGlyc1ZUZnkzNXIxL3kzZFMzV2kzWDFTNG1UMHBIOU9PU3ENClZEVXBLcmpxTXJ5WW96RlNES016SGt5SC9sZGY1bS85WG4vcDJ0UCtxV1Uva3NYZDlwWitQUHZkL3dBcnIvTTMvcTgvOU8xcC93QlUNCnNmeVdMdSswcjQ4KzkzL0s2L3pOL3dDcnovMDdXbi9WTEg4bGk3dnRLK1BQdlFPdC9taDU2MXZUSnRMMVRVL3JGamNjZldoOUMzVGwNCndjT3Z4SkdyQ2pLRHNjbERTNDRtd04vaWlXV1JGRXNWeklhM1lxN0ZYWXE3RlhZcTdGWFlxajlEMFBWTmMxT0hUZE1nYTR1NXpSVVgNCm9CM1pqMFZSM0p5RTVpSXM4a3hpU2FENmcvTG44dWRPOG02YXlxd3VkVnVRUHJsNVNsYWJpT091NFFmajFQWURSYW5VbklmSjJHTEUNCklqelpmbU0ydXhWMkt1eFYyS3V4VjJLdXhWMktzYjg3K1F0RDgzYWQ5V3YwOU82akIrcVh5QWVwRXgvNGtwN3FldnozeS9CbmxqTmgNCnJ5WXhJYnZtYnpsNUYxN3luZm0yMUtLc0RrL1ZyMk1Fd3lqL0FDVzdONHFkODNtSFBISUxEZ1R4bUozWTlsekIyS3V4VjJLdXhWMksNCnV4VjJLdXhWMkt1eFYyS3V4VjJLdXhWMkt1eFYyS3NoOG0rUmRlODJYNHR0TmlwQWhIMW05a0JFTVEveW03dDRLTjhwelo0NHhaWncNCnhtUjJmVFBranlGb2ZsSFR2cTFnbnFYVWdIMXUrY0QxSldIL0FCRlIyVWRQbnZtano1NVpEWmMvSGpFUnN5VEtHeDJLdXhWMkt1eFYNCjJLdXhWMkt1eFYyS3V4VkM2cHBXbTZyWXkyT28yNlhWcE1LU1F5Q29QdVBBanNSdU1sR1ppYkhOQkFJb3ZDZlBmNUNhbFltUys4c0YNCnI2ejNackJ6L3BDRC9JUFNRZjhBRGZQTnRnMTRPMDlpNGVUVGtiaDVKTEZMREswVXFOSEtoS3ZHNEtzcEhVRUhjWnNRYmNaWmlyc1YNCmRpcnNWZGlyc1ZkaXJzVmRpcnNWZGlyc1ZkaXJzVlh4UlN6U3JGRWpTU3VRcVJvQ3pNVDBBQTNPSk5LOWI4aWZrSnFWOFk3N3pPV3MNCmJQWmxzRVAra09QOHM5SXgvd0FOOHMxMmZYZ2JRM0xrNDlPVHVYdTJsNlZwMmxXVWRqcDF1bHJhUWlrY01ZNGdlL3VUM0ozT2FtVXoNCkkyZWJtQUFiQkZaRkxzVmRpcnNWZGlyc1ZkaXJzVmRpcnNWZGlyc1ZkaXJzVll6NXUvTHJ5cjVwalA2U3RRbDNTaVg4Rkk1MTdENHENCkhrUFpnUmwrSFVUeDhqczF6eFJsemVMK2F2eUQ4MDZZWG4wZGwxZTBHNFJhUjNDajNqWThXLzJMVjlzMmVMWHdsOVd4Y1dlbkk1YnYNCk5idXp1N080ZTN1NEpMZTRqTkpJWlZaSFUrNnNBUm1jQ0NMRGprVW80VmRpcnNWZGlyc1ZkaXJzVmRpcnNWZGlxdGFXZDNlWENXOXANCkJKY1hFaHBIREVyTzdIMlZRU2NCSUFzcUJiMHJ5cCtRZm1qVTJTZldXWFNMTTdsR3BKY01QWkZQRmY4QVpOVWVHWU9YWHdqOU81Y2kNCkduSjU3UGFmS1g1ZGVWZkswUS9SdHFIdTZVZS9ubzg3ZVB4VUhFZXlnRE5abTFFOG5NN09WREZHUEprdVVOanNWZGlyc1ZkaXJzVmQNCmlyc1ZkaXJzVmRpcnNWZGlyc1ZkaXJzVmRpcnNWUy9XUEwyaDYxQjZPcTJNRjdHTmw5WkF6TFgrVnZ0TDlCeWNNa284alRHVVFlYnoNCnpYUCtjZXZLZDRXZlM3bTQwdVE5RXI5WWlIK3hjaC8rSHpNaDJoTWM5Mm1XbWllVEJkVi81eDY4NVdwWnJDNHRkUWovQUdRSE1NaCsNCmF1T0Evd0NEekxoMmhBODdEU2ROTG94YS93RHl3L01DeEo5ZlFycHFkVEFvdUIveVJNbVpFZFZqUDhRYXppa09pUjNHaTZ4YkdselkNCjNFQjhKSW5UdFg5b0RMUk9KNUZnWWxCNUpEc1ZSbHZvdXNYSnBiV054T2ZDT0ozN1YvWkJ5Sm5FY3lrUktlV0g1WWZtQmZFZWhvVjANCnRlaG5VVzQvNUxHUEtwYXJHUDRnekdLUjZNcDByL25IcnpsZEZXdjdpMTArUDlvRnpOSVBrcURnZitEekhuMmhBY3JMWU5OTHF6clENCi93RG5IcnluWmxYMVM1dU5Va0hWSy9WNGovc1VKZjhBNGZNU2ZhRXp5MmJvNmFJNXZROUg4dmFIb3NIbzZWWXdXVVoyYjBVQ3MxUDUNCm0rMDMwbk1PZVNVdVp0dWpFRGttR1FaT3hWMkt1eFYyS3V4VjJLdXhWMkt1eFYvLzJRPT08L3htcEdJbWc6aW1hZ2U+DQoJCQkJCTwvcmRmOmxpPg0KCQkJCTwvcmRmOkFsdD4NCgkJCTwveG1wOlRodW1ibmFpbHM+DQoJCQk8eG1wTU06UmVuZGl0aW9uQ2xhc3M+cHJvb2Y6cGRmPC94bXBNTTpSZW5kaXRpb25DbGFzcz4NCgkJCTx4bXBNTTpPcmlnaW5hbERvY3VtZW50SUQ+dXVpZDo2NUU2MzkwNjg2Q0YxMURCQTZFMkQ4ODdDRUFDQjQwNzwveG1wTU06T3JpZ2luYWxEb2N1bWVudElEPg0KCQkJPHhtcE1NOkRvY3VtZW50SUQ+eG1wLmRpZDphNDlkYzA5Yy0wMWQwLWUzNDAtODI5YS00ZDA3MWRmY2I1YmE8L3htcE1NOkRvY3VtZW50SUQ+DQoJCQk8eG1wTU06SW5zdGFuY2VJRD54bXAuaWlkOmE0OWRjMDljLTAxZDAtZTM0MC04MjlhLTRkMDcxZGZjYjViYTwveG1wTU06SW5zdGFuY2VJRD4NCgkJCTx4bXBNTTpEZXJpdmVkRnJvbSByZGY6cGFyc2VUeXBlPSJSZXNvdXJjZSI+DQoJCQkJPHN0UmVmOmluc3RhbmNlSUQ+eG1wLmlpZDpkNDdhYzVjNC0xYjc5LTMwNGYtYTU4ZC1iYzFkYzVmMWM3YWM8L3N0UmVmOmluc3RhbmNlSUQ+DQoJCQkJPHN0UmVmOmRvY3VtZW50SUQ+eG1wLmRpZDpkNDdhYzVjNC0xYjc5LTMwNGYtYTU4ZC1iYzFkYzVmMWM3YWM8L3N0UmVmOmRvY3VtZW50SUQ+DQoJCQkJPHN0UmVmOm9yaWdpbmFsRG9jdW1lbnRJRD51dWlkOjY1RTYzOTA2ODZDRjExREJBNkUyRDg4N0NFQUNCNDA3PC9zdFJlZjpvcmlnaW5hbERvY3VtZW50SUQ+DQoJCQkJPHN0UmVmOnJlbmRpdGlvbkNsYXNzPnByb29mOnBkZjwvc3RSZWY6cmVuZGl0aW9uQ2xhc3M+DQoJCQk8L3htcE1NOkRlcml2ZWRGcm9tPg0KCQkJPHhtcE1NOkhpc3Rvcnk+DQoJCQkJPHJkZjpTZXE+DQoJCQkJCTxyZGY6bGkgcmRmOnBhcnNlVHlwZT0iUmVzb3VyY2UiPg0KCQkJCQkJPHN0RXZ0OmFjdGlvbj5zYXZlZDwvc3RFdnQ6YWN0aW9uPg0KCQkJCQkJPHN0RXZ0Omluc3RhbmNlSUQ+eG1wLmlpZDpiODI0ZjA4YS1hYTI3LTQyNGMtOTFmMy0zY2E3YjZjNWYwZDI8L3N0RXZ0Omluc3RhbmNlSUQ+DQoJCQkJCQk8c3RFdnQ6d2hlbj4yMDE4LTAyLTE5VDE1OjU0OjE3KzA3OjAwPC9zdEV2dDp3aGVuPg0KCQkJCQkJPHN0RXZ0OnNvZnR3YXJlQWdlbnQ+QWRvYmUgSWxsdXN0cmF0b3IgQ0MgMjIuMCAoV2luZG93cyk8L3N0RXZ0OnNvZnR3YXJlQWdlbnQ+DQoJCQkJCQk8c3RFdnQ6Y2hhbmdlZD4vPC9zdEV2dDpjaGFuZ2VkPg0KCQkJCQk8L3JkZjpsaT4NCgkJCQkJPHJkZjpsaSByZGY6cGFyc2VUeXBlPSJSZXNvdXJjZSI+DQoJCQkJCQk8c3RFdnQ6YWN0aW9uPnNhdmVkPC9zdEV2dDphY3Rpb24+DQoJCQkJCQk8c3RFdnQ6aW5zdGFuY2VJRD54bXAuaWlkOmE0OWRjMDljLTAxZDAtZTM0MC04MjlhLTRkMDcxZGZjYjViYTwvc3RFdnQ6aW5zdGFuY2VJRD4NCgkJCQkJCTxzdEV2dDp3aGVuPjIwMTgtMDItMTlUMTY6NTU6NDIrMDc6MDA8L3N0RXZ0OndoZW4+DQoJCQkJCQk8c3RFdnQ6c29mdHdhcmVBZ2VudD5BZG9iZSBJbGx1c3RyYXRvciBDQyAyMi4wIChXaW5kb3dzKTwvc3RFdnQ6c29mdHdhcmVBZ2VudD4NCgkJCQkJCTxzdEV2dDpjaGFuZ2VkPi88L3N0RXZ0OmNoYW5nZWQ+DQoJCQkJCTwvcmRmOmxpPg0KCQkJCTwvcmRmOlNlcT4NCgkJCTwveG1wTU06SGlzdG9yeT4NCgkJCTxpbGx1c3RyYXRvcjpTdGFydHVwUHJvZmlsZT5XZWI8L2lsbHVzdHJhdG9yOlN0YXJ0dXBQcm9maWxlPg0KCQkJPHBkZjpQcm9kdWNlcj5BZG9iZSBQREYgbGlicmFyeSAxNS4wMDwvcGRmOlByb2R1Y2VyPg0KCQk8L3JkZjpEZXNjcmlwdGlvbj4NCgk8L3JkZjpSREY+DQo8L3g6eG1wbWV0YT4NCiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAKICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIAogICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgCiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAKICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIAogICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgCiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAKICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIAogICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgCiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAKICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIAogICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgCiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAKICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIAogICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgCiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAKICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIAogICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgCiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAKICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIAogICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgCiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAKICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIAogICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgCiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAKICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIAogICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgCiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAKICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIAogICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgCiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAKICAgICAgPD94cGFja2V0IGVuZD0ndyc/Pv/iDFhJQ0NfUFJPRklMRQABAQAADEhMaW5vAhAAAG1udHJSR0IgWFlaIAfOAAIACQAGADEAAGFjc3BNU0ZUAAAAAElFQyBzUkdCAAAAAAAAAAAAAAAAAAD21gABAAAAANMtSFAgIAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAEWNwcnQAAAFQAAAAM2Rlc2MAAAGEAAAAbHd0cHQAAAHwAAAAFGJrcHQAAAIEAAAAFHJYWVoAAAIYAAAAFGdYWVoAAAIsAAAAFGJYWVoAAAJAAAAAFGRtbmQAAAJUAAAAcGRtZGQAAALEAAAAiHZ1ZWQAAANMAAAAhnZpZXcAAAPUAAAAJGx1bWkAAAP4AAAA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"
            alt="facebook-logo"></a>
            <a target="_blank" href="https://www.instagram.com/newnesselectronic/"><img src="data:image/jpg;base64,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"
            alt = "instagram-logo"></a>
            <a target="_blank" href="https://youtube.com/channel/UCuv9rrbMW3BZuZJ7zMM6HCw"><img src="data:image/jpg;base64,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"
            alt = "youtube"></a>
            <a target="_blank" href="mailto:newnesselectronics@gmail.com"><img src="data:image/jpg;base64,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"
            alt = "gmail"></a>
           </section> 
        </section>
    </main>
</body>

</html>
)rawliteral";

const char login_html[] = R"rawliteral(
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Login</title>
    <style>
        * {
            margin: 0;
            padding: 0;
            box-sizing: border-box;
        }

        body {
            font-family: Verdana, Geneva, Tahoma, sans-serif;
            background-image: linear-gradient(45deg, rgb(255, 255, 255), #fff, #fff, rgb(141, 207, 158), rgb(123, 190, 192), rgb(130, 129, 180),
                    rgb(160, 103, 132), rgb(145, 70, 74), rgb(122, 55, 55));
            background-size: 2000% 2000%;
            background-repeat: no-repeat;
            animation: gradient 20s ease infinite;
        }

        @keyframes gradient {
            0% {
                background-position: 0% 50%;
            }

            50% {
                background-position: 100% 50%;
            }

            100% {
                background-position: 0% 50%;
            }
        }

        .container {
            width: 100%;
            height: 100vh;
        }

        a {
            text-decoration: none;
        }

        .logo {
            display: flex;
            padding: 5px;
            margin-right: 5px;
            flex-direction: row;
            justify-content: flex-start;
            align-items: center;
        }

        .logo>img {
            width: 20%;
            margin-right: 5px;
            border-radius: 5px;
        }

        .logo>p {
            font-size: 1.2em;
        }

        /* STYLES FOR OTHER PAGES */
        .btn, .form-control {
            /* margin:15px 0px; */
            padding: 11px;
            border-radius: 5px;
            font-size: 1.2em;
            border: none;
            background-color: rgb(27, 81, 83);
            color: white;
            margin: 10px;
        }

        .btn:hover {
            transition: 0.5s ease;
            background-color: black;
            color: gold;
        }

        .login-center {
            width: 80%;
            padding: 20px;
            max-width: 400px;
            /* margin: 20px auto; */
            background-color: rgba(255, 255, 255, 0.397);
            height: 250px;
            border-radius: .25rem !important;
            box-shadow: 0 .5rem 1rem rgba(0, 0, 0, .15) !important;
            display: flex;
            flex-direction: column; 
        }

        /* END OF LOG IN PAGE STYLES */


        @media (max-width: 768px) {
            .logo>p {
                font-size: 1em;
            }
        }

        .navbar {
        display: flex;
        align-items: center;
        justify-content: space-between;
        padding: 10px;
        background-color: teal;
        color: #fff;
        border-radius: 1px;
       }

       .login-container{
            display: flex;
            justify-content: center;
            margin: 15vh 0px;
       }
       
    </style>
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.2.1/jquery.min.js"></script>

<body>
    <!-- Start: login form -->
    <div class="container">
        <div class = "navbar">
        <div class="logo">
            <img src="data:image/png;base64,/9j/4AAQSkZJRgABAQEAYABgAAD/4QAiRXhpZgAATU0AKgAAAAgAAQESAAMAAAABAAEAAAAAAAD/2wBDAAIBAQIBAQICAgICAgICAwUDAwMDAwYEBAMFBwYHBwcGBwcICQsJCAgKCAcHCg0KCgsMDAwMBwkODw0MDgsMDAz/2wBDAQICAgMDAwYDAwYMCAcIDAwMDAwMDAwMDAwMDAwMDAwMDAwMDAwMDAwMDAwMDAwMDAwMDAwMDAwMDAwMDAwMDAz/wAARCAArACIDASIAAhEBAxEB/8QAHwAAAQUBAQEBAQEAAAAAAAAAAAECAwQFBgcICQoL/8QAtRAAAgEDAwIEAwUFBAQAAAF9AQIDAAQRBRIhMUEGE1FhByJxFDKBkaEII0KxwRVS0fAkM2JyggkKFhcYGRolJicoKSo0NTY3ODk6Q0RFRkdISUpTVFVWV1hZWmNkZWZnaGlqc3R1dnd4eXqDhIWGh4iJipKTlJWWl5iZmqKjpKWmp6ipqrKztLW2t7i5usLDxMXGx8jJytLT1NXW19jZ2uHi4+Tl5ufo6erx8vP09fb3+Pn6/8QAHwEAAwEBAQEBAQEBAQAAAAAAAAECAwQFBgcICQoL/8QAtREAAgECBAQDBAcFBAQAAQJ3AAECAxEEBSExBhJBUQdhcRMiMoEIFEKRobHBCSMzUvAVYnLRChYkNOEl8RcYGRomJygpKjU2Nzg5OkNERUZHSElKU1RVVldYWVpjZGVmZ2hpanN0dXZ3eHl6goOEhYaHiImKkpOUlZaXmJmaoqOkpaanqKmqsrO0tba3uLm6wsPExcbHyMnK0tPU1dbX2Nna4uPk5ebn6Onq8vP09fb3+Pn6/9oADAMBAAIRAxEAPwD9yZkt9G0ye8vJ4LSztImnnnncRxQxqCWd2OAqgAkknAAJNfjd+37/AMHQ2o6N46ufDv7Oui+H7zRNPZoZvF3iC0kuP7ScH71lah4wkQxxLPvMm44iQBXf66/4ONfit4k+Gf8AwTN1PRPCsOpTal8TPEGn+DJF0+OSS6kt7nzZZYI0TLObhbf7MUAJdbllAJYV+GF74B0bwNYW/hnxN4B0PTbrQomju/FOpapcWM93cFmkm3Wj39ulzbxFvIikttrOkPnfvt6xL9JkuX0Zx9vXXNrZL06s+Vz7Mq9OSw+HfLpq/XZL9WfY/wCzf/wdN/GDwj4+sV+Knhfwh418ISzBb/8AsewOl6xbxkgM8D+aYHZRlhFIi+YQF82IHcP2w+AXxy8G/tW/BrRfH3gHWYde8K+IIWltLtEZGBVikkUkbANHKjqyOjAFWUg1/NF4n+Fui/AP4gSaVdeBfhl8UNe0maI3On6X4g1S2scMiS+WIpryO/uHaOQdLeJEfH/HwMpX6M/8Gv8AfeK/hB8YPjH8JNUj1seF7zS7DxrorajZPZs++RrU3IjYfK88YijlUEiOWweLO6JxW+b4DDul7eguVrp0a9O6/E58jzDF+2+r4mXMn16p+b7P8z9am0w5+7RW0YTmivlD7I/Jf/g5i+PnjDwJ8ev2cvCNrqF1p/gfVr461ewRqoXUby11GwZGLkble3G0qUKkfaXBJDYr8mvg54Kb4s+JZ/El5Hp9vrXgtLjVdWn1KaK20/xPJZwSXIjkklKp9skMI85QSZoTNOQHilab+kv/AIKjf8E6/Df/AAUM+AMdjfWcz+M/Bf2jWvB91DMkDDUBA3l20zsMm0nkWETIGQsI0IdGRXH88raVqXx38cx+MvD/AIN8RaRH4dvRNeQadG8+leA7vzS72Nzp8qF1jkkRygM++7CyJia4S4RPsslxEHhuSGjju/V/rt8vQ+Gz7C1FivaS1jK1l6JX+7f59jjr74VnUvg7pXjTXrjT/ESeHZbzSbqx03V4b661RYzHdpPcNFI0iQKb1455v4ES0jUo0yyJ9b/8EPf2lPHml/8ABTL4CeH9P1mZdJ8d6Le6fr+mRxRR29zZ2v8AwkVxbQoNv7mG33CRIoii/IowQBXgPj74GWega3Z614L034mP4F8IxKIdc1C0k8ODwsjSNJJPfnZPMS00zJG6bGmBggjaSZRFX7Bf8EE/2HvCdz4A0j9pe98Ht4b8VeJtLn0Xw3YGPybWz0ZZdiagtuS/lXV6Y3lZ438oRTBYVSN2MnRmWKhHDS59b3S8m9tPx+Xoc2U4WrLFR5Ha1m/O3X9Ox+jjKM0UrDJor4U/QhZdattJ06a6vLiG0s7WNp5p5pAkcEagszsxOFUAEkngAV/Hn+1F+0TpH7RP7SPxG8eaXFHomk+PvFF/4ki043W4w/aLiaZDJk8yATOSegaRwuFOK/sChPy47HII9asrDGV/1UP/AH7H+FerleZLBylLl5r+dv0Z4+cZT9fhGDnypO+1z+Lj/hIrcQTRx6hFEtxH5Um24A3ruVgCM8gMqtg8ZVT1Ar+sT/gk7+0FoP7SX/BNv4O+JvDdjb6Vpq+HYNGNhA++Kwm0/NhNChPOxZLZthPJTaT1r6E8mMD/AFUX/fAqrcfu1O0KvPRRitc0zhYyEY8nK0+9/wBEY5Pkn1CUpKfMmu3/AARxn5/+vRWe8jbzz3orxT3j/9k=" alt="face logo" />
            <p>faceApp</p>
          </div>
        </div>

        <div class = "login-container">
            <form action  ="/logged" class="login-center">
            <input class="form-control" type="text" placeholder="Username" name="LOGINUSER">
            <input class="form-control" type="password" placeholder="Password" name="LOGINPASS">
            <button class="btn" type="submit">Login</button>
        </form>
        </div>
    </div><!-- End: login form -->
</body>
</html>
)rawliteral";
