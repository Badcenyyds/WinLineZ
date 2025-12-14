# WinLineZ

这是一个基于 C++ 语言和 Raylib 编写的对经典游戏 WinLine 的模仿。

试玩这个项目而不是原版的理由：
- 我实现的版本具有高度优化的显示效果和操作手感，平滑且自然的移动，以及令人激动的记分系统。
- 相信我，实际游玩的感受绝对会比下面的截图更加生动！
- 既然已经看到这里了，为什么不试试呢？

下面是游戏规则（相对原版略有修改：
- 在 9x9 的平面方格上，每回合会在空的格子上随机出现 3 个 7 种颜色之一的球，同时占据这个格子。
- 移动小球并形成长度至少为 5 的 横/竖/斜 的连续段，并消除他们！一步消除 $x$ 个球会让你获得 $2^x$ 分。
- 如果平面被填满了，你就输了！反之如果你在此之前得到了 1024 分，你就获胜了！

游戏截图：
<img width="1002" height="1027" alt="image" src="https://github.com/user-attachments/assets/d8d4257d-9bf5-48c5-86c4-c39339fac283" />

消除特效：
<img width="1002" height="1027" alt="image" src="https://github.com/user-attachments/assets/35ccaafb-f48a-4f4f-aee8-724ae05b68a4" />

哦不我输了 T_T
<img width="1002" height="1027" alt="image" src="https://github.com/user-attachments/assets/ef9cf513-acfa-4904-a29a-23457505ab82" />

计划加入的功能：更多的自定义技能，可持久化的计分，等。

不幸地，由于我在在 vscode 上配置 raylib 的尝试上失败了多次。我最终选用了 [小熊猫c++](http://royqh.net/redpandacpp/) 作为开发环境。所以其他人可能不能开箱即用 :<

不过我相信对于任何想要修改然后编译我的代码而不仅仅是游玩的人来说这并非难事 :>
