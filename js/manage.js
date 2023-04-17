let add_face_btn = document.getElementById("add-face");
let remove_face_btn = document.getElementById("remove-face");
let face_list_btn = document.getElementById("face-list");
let main_manage_btn = document.getElementById("main-manage-buttons");

add_face_btn.addEventListener("click", () => {
  let pop_up = document.getElementById("face-stream-container");
  let stream = document.getElementById("stream");
  //  let container = document.getElementById("face-buttons");
  let streamUrl = `${window.location.origin}+:81/stream`;

  stream.style.width = "100%";
  stream.style.borderRadius = "10px";
  //  stream.src = "images/face-banner-mobile.jpg";
  stream.src = streamUrl;
  pop_up.classList.toggle("hidden");
});

remove_face_btn.addEventListener("click", () => {
  let pop_up = document.getElementById("remove-face-container");
  pop_up.classList.toggle("hidden");
});

face_list_btn.addEventListener("click", () => {
  let pop_up = document.getElementById("face-list-container");
  pop_up.classList.toggle("hidden");
});
