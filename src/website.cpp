#include "website.h"

WebServer server(80); // Create a web server object that listens on port 80

bool condition = false;

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Telegram Bot</title>
  <style>
    html, body { padding: 0; margin: 0; }
    .container { background-color: #c4c4c4; width: 100vw; height: 100vh; display: flex; justify-content: center; align-items: center; }
    main { width: 500px; }
    .form { display: flex; flex-direction: column; gap: 10px; background-color: white; padding: 2.5em; border-radius: 25px; transition: .4s ease-in-out; box-shadow: rgba(0, 0, 0, 0.4) 1px 2px 2px; }
    .form:hover { transform: translateX(-0.5em) translateY(-0.5em); border: 1px solid #171717; box-shadow: 10px 10px 0px #666666; }
    .heading { color: black; padding-bottom: 2em; text-align: center; font-weight: bold; }
    .input { border-radius: 5px; border: 1px solid whitesmoke; background-color: whitesmoke; outline: none; padding: 0.7em; transition: .4s ease-in-out; }
    .input:hover { box-shadow: 6px 6px 0px #969696, -3px -3px 10px #ffffff; }
    .input:focus { background: #ffffff; box-shadow: inset 2px 5px 10px rgba(0, 0, 0, 0.3); }
    .form .btn { margin-top: 2em; align-self: center; padding: 0.7em; padding-left: 1em; padding-right: 1em; border-radius: 10px; border: none; color: black; transition: .4s ease-in-out; box-shadow: rgba(0, 0, 0, 0.4) 1px 1px 1px; }
    .form .btn:hover { box-shadow: 6px 6px 0px #969696, -3px -3px 10px #ffffff; transform: translateX(-0.5em) translateY(-0.5em); }
    .form .btn:active { transition: .2s; transform: translateX(0em) translateY(0em); box-shadow: none; }
    .alert { display: none; border-radius: 25px; padding: 20px; background-color: #f44336; color: white; }
    .closebtn { margin-left: 15px; color: white; font-weight: bold; float: right; font-size: 22px; line-height: 20px; cursor: pointer; transition: 0.3s; }
    .closebtn:hover { color: black; }
    .checkbox-wrapper-46 input[type="checkbox"] { display: none; visibility: hidden; }
    .checkbox-wrapper-46 .cbx { margin: auto; -webkit-user-select: none; user-select: none; cursor: pointer; }
    .checkbox-wrapper-46 .cbx span { display: inline-block; vertical-align: middle; transform: translate3d(0, 0, 0); }
    .checkbox-wrapper-46 .cbx span:first-child { position: relative; width: 18px; height: 18px; border-radius: 3px; transform: scale(1); vertical-align: middle; border: 1px solid #9098a9; transition: all 0.2s ease; }
    .checkbox-wrapper-46 .cbx span:first-child svg { position: absolute; top: 3px; left: 2px; fill: none; stroke: #ffffff; stroke-width: 2; stroke-linecap: round; stroke-linejoin: round; stroke-dasharray: 16px; stroke-dashoffset: 16px; transition: all 0.3s ease; transition-delay: 0.1s; transform: translate3d(0, 0, 0); }
    .checkbox-wrapper-46 .cbx span:first-child:before { content: ""; width: 100%; height: 100%; background: #506eec; display: block; transform: scale(0); opacity: 1; border-radius: 50%; }
    .checkbox-wrapper-46 .cbx span:last-child { padding-left: 8px; }
    .checkbox-wrapper-46 .cbx:hover span:first-child { border-color: #506eec; }
    .checkbox-wrapper-46 .inp-cbx:checked+.cbx span:first-child { background: #506eec; border-color: #506eec; animation: wave-46 0.4s ease; }
    .checkbox-wrapper-46 .inp-cbx:checked+.cbx span:first-child svg { stroke-dashoffset: 0; }
    .checkbox-wrapper-46 .inp-cbx:checked+.cbx span:first-child:before { transform: scale(3.5); opacity: 0; transition: all 0.6s ease; }
    @keyframes wave-46 { 50% { transform: scale(0.9); } }
  </style>
</head>
<body>
  <div class="container">
    <main>
      <form class="form">
        <p class="heading">Bot Telegram</p>
        <div class="alert">
          <span class="closebtn" onclick="this.parentElement.style.display='none';">&times;</span>
          <strong>Wrong!</strong> <span id="text"></span>
        </div>
        <input id="botToken" class="input" placeholder="Bot Token" type="text" autocomplete="off" autofocus>
        <input id="chatID" class="input" placeholder="ChatID" type="text" autocomplete="off">
        <div class="checkbox-wrapper-46">
          <input type="checkbox" id="cbx-46" class="inp-cbx" />
          <label for="cbx-46" class="cbx"><span>
              <svg viewBox="0 0 12 10" height="10px" width="12px">
                <polyline points="1.5 6 4.5 9 10.5 1"></polyline>
              </svg></span><span>Simpan token dan chatID</span>
          </label>
        </div>
        <button class="btn" type="submit">Submit</button>
      </form>
    </main>
  </div>
</body>
<script>
  function alertMessage(bool, text) {
    const alertMessageDisplay = document.querySelector(".alert")
    alertMessageDisplay.style.display = "block"
    document.getElementById("text").textContent = text
    if (bool) {
      document.querySelector("strong").textContent = "Success!"
      alertMessageDisplay.style.backgroundColor = " #04AA6D"
    } else {
      alertMessageDisplay.style.backgroundColor = "#f44336"
    }
  }

  document.querySelector(".form").addEventListener("submit", async function (event) {
    event.preventDefault();
    const botToken1 = document.getElementById("botToken").value
    const chatID1 = document.getElementById("chatID").value
    const remember1 = document.querySelector(".inp-cbx").checked

    if (botToken1 == "" || chatID1 == "") {
      alertMessage(false, "Harus mengisi form")
      return
    }

    const sendData = `botToken=${encodeURIComponent(botToken1)}&chatID=${encodeURIComponent(chatID1)}&remember=${encodeURIComponent(remember1)}`
    const options = {
      method: 'POST',
      headers: {
        'Content-Type': 'application/x-www-form-urlencoded',

      },
      body: sendData
    };

    console.log(sendData)

    try {
      const response = await fetch(`http://${window.location.hostname}/submit`, options)
      const data = await response.json();
      console.log(data)
      if (data.status == "success") {
        alertMessage(true, "Berhasil Tersambung dengan telegram")
        setTimeout(() => {}, 2000);
        window.close()
      } else {
        alertMessage(false, "Ada yang salah token atau chatid")
      }
    } catch (error) {
      console.log(error)
      alertMessage(false, "Adalah kesalahan alat tolong coba lagi")
    }
  });
</script>
</html>
)rawliteral";
void handlePageForm()
{

  server.send(200, "text/html", index_html);
}

void handleSubmit()
{

  if (server.hasArg("botToken") && server.hasArg("chatID") && server.hasArg("remember"))
  {
    String token = server.arg("botToken");

    if (checkTelegram(token))
    {
      Serial.println("masuk");
      botToken = token;
      chatID = server.arg("chatID");
      bool remember = server.arg("remember");
      if (remember)
      {
        Serial.println("masuk");
        saveTelegramToRom(botToken, chatID);
      }

      condition = true;

      String jsonResponse = "{\"status\": \"success\"}";

      server.send(400, "application/json", jsonResponse);
    }
    else
    {
      Serial.println("tidak masuk");
      String jsonResponse = "{\"status\": \"failed\"}";

      server.send(400, "application/json", jsonResponse);
    }
  }
  else
  {
    String jsonResponse = "{\"status\": \"failed server\"}";

    server.send(400, "application/json", jsonResponse);
  }
}

void inializationWebsite()
{
  // Tentukan URL untuk halaman root dan fungsi handler
  server.on("/", handlePageForm);
  server.on("/submit", handleSubmit);

  // Mulai web server
  server.begin();
}
void executeWebsite()
{
  server.handleClient();
}

bool isSubmited()
{
  return condition;
}
