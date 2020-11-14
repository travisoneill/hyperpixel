
function uploadListener(event) {
  event.preventDefault();
  const files = document.querySelector('#file-upload').files;
  for (const file of files) {
    uploadFile(file);
  }
}

async function uploadFile(file) {

  const data = new FormData();
  data.append('project', 'example');
  data.append('name', file.name);
  data.append('file', file);

  const res = await fetch('/upload', {
    method: 'POST',
    body: data,
  });

  const json = await res.json();
  console.log(json);

}

document.addEventListener('DOMContentLoaded', event => {
  document.querySelector('#file-submit').addEventListener('click', uploadListener);
});
