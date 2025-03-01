// 获取元素
const audio = document.getElementById('bg-music');
const musicIcon = document.querySelector('.music-icon');

// 初始化播放状态
let isPlaying = localStorage.getItem('musicPlaying') === 'true';

// 设置初始状态
if(isPlaying) {
    audio.play().catch(() => {
        // 处理自动播放被阻止的情况
        isPlaying = false;
        updateIcon();
    });
}
updateIcon();

// 切换播放状态
function toggleMusic() {
    isPlaying = !isPlaying;
    localStorage.setItem('musicPlaying', isPlaying);

    if(isPlaying) {
        audio.play();
    } else {
        audio.pause();
    }
    updateIcon();
}

// 更新按钮图标
function updateIcon() {
    musicIcon.classList.toggle('paused', !isPlaying);
}

// 绑定点击事件
document.getElementById('musicBtn').addEventListener('click', toggleMusic);

// 首次尝试自动播放（需要用户交互）
// 监听整个页面的点击事件，当用户首次点击页面任意位置时触发回调函数
// 当用户第一次点击页面时，检查isplaying状态，如果之前是播放状态，尝试播放音乐，立即移除事件监听器，避免重复触发
document.addEventListener('click', function initPlay() {
    if(isPlaying) audio.play();
    document.removeEventListener('click', initPlay);
});
