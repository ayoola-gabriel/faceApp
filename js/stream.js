let stream_btn = document.getElementById("stream-btn");
let baseHost = location.origin;
let streamUrl = baseHost + ":81";

let img = document.getElementById("stream");

window.addEventListener("DOMContentLoaded", () => {
  // img.src = "images/face-banner-mobile.jpg";
  img.src = `${streamUrl}/stream`;
  img.style.width = "100%";
  img.style.borderRadius = "10px";

  stream_btn.addEventListener("click", function () {
    document.getElementById("stream-container").classList.toggle("hidden");
    if (stream_btn.innerHTML === "Start Stream") {
      stream_btn.innerHTML = "Stop Stream";
    } else {
      stream_btn.innerHTML = "Start Stream";
    }

    // img.remove();
    //setTimeout(window.open(`${baseHost}`,'_self'),3000);
  });
});
