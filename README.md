Tên game: Monsters War
Lối chơi, logic của game:
- Lối chơi: 
Người chơi xây dựng đội hình gồm các Quái thú (Monster), đánh bại đội đối thủ ở mỗi màn để dành chiến thắng và mở các màn chơi mới.
Mỗi Quái thú sẽ có các chỉ số: Hp (Lượng máu cơ bản), Atk (Sát thương mỗi lần tấn công), Def (Phòng thủ, giảm sát thương nếu bị chịu đòn đánh), Accuracy (Tỉ lệ chuẩn xác của mỗi đòn đánh, đơn vị %), CritChance (Tỉ lệ chí mạng của mỗi đòn đánh, nhân đôi sát thương gây ra, đơn vị %).
Người chơi nhận được Gold và Food mỗi khi chiến thắng một màn chơi. Sử dụng Gold để chiêu mộ Quái thú, dùng Food để nâng cấp Quái thú trở nên mạnh hơn.
- Khi vào game, người chơi ấn nút Start để hiển thị bản đồ chính. Trên bản đồ chính gồm:
Các màn chơi biểu thị bởi các nút: màu Xanh (đã chiến thắng), Vàng (màn chơi tiếp theo), Trắng (màn chơi chưa được mở khóa), Đỏ (màn chơi có độ khó rất cao). Ấn vào các nút mà chơi hiển thị lựa chọn tham gia màn chơi. Khi vào màn chơi có ô Cờ trắng, người chơi ấn vào để đầu hàng.
Hai ô Gold và Food: thể hiện chỉ số Gold và Food của người chơi.
Ô Kính lúp: khi ấn vào hiển thị bảng chiêu mộ. Người chơi dùng vàng để làm mới bảng chiêu mộ và chiêu mộ Quái thú.
Ô Balo: khi ấn vào hiển thị danh sách Quái thú của người chơi. Người chơi có thể chọn nâng cấp Quái thú, chọn và loại Quái thú ra khỏi đội hình.
Ô Cửa: Thoát game.
Đồ họa, âm thanh:
Hình ảnh gồm bản đồ chính, các nút chức năng, hình ảnh bối cảnh mỗi màn chơi và hình ảnh các Quái thú.
Âm thanh: gồm âm thanh click chuột, âm thanh ở bản đồ chính, âm thanh bối cảnh chiến đấu.
Cấu trúc của project game:
main.cpp: Chương trình chính.
CreateMap.cpp: Cập nhật và hiển thị các thông tin trên bản đồ chính. Người chơi click vào các nút chức năng trên bản đồ chính.
GameOn.cpp: Hiển thị màn hình cốt truyện khi người chơi click vào một màn chơi và đưa ra lựa chọn có bắt đầu màn chơi hay không. Sau khi kết thúc màn chơi hàm này dựa vào kết quả và tăng/ không tăng Gold hoặc Food cho người chơi đồng thời cập nhật trạng thái hoàn thành/ chưa hoàn thành của một màn chơi.
Combat.cpp: Hiển thị bối cảnh chiến đấu của các Quái thú. Đây là hàm logic trả về true nếu người chơi thắng, trả về false nếu người chơi thua. Cơ chế chiến đấu: các Quái thú  cận chiến sẽ di chuyển đến khi gặp được Quái thú bên đối thủ. Hai Quái thú gặp nhau sẽ giao chiến, hiển thị bởi thanh máu ở bên dưới. Người chơi chiến thắng khi hạ được toàn bộ Quái thú của đối thủ và ngược lại.
Shopping.cpp: Hiển thị cửa hàng mua sắm Quái thú. Tại đây có các lựa chọn đổi Gold thành Food, đổi Food thành Gold, sử dụng Gold để làm mới cửa hàng, mua sắm Quái thú.
ShowInventory.cpp: Hiển thị danh sách Quái thú, cho biết thông số sức mạnh. Quái thú trong đội chiến đấu ấn vào nút X sẽ rời khỏi đội chiến đấu, Quái thú không trong đội chiến đấu ấn nút V để thêm vào đội. Một đội chiến đấu có tối đa bốn Quái thú. Người chơi cũng có thể ấn vào nút thùng rác để thả Quái thú đi (Nếu trong danh sách có nhiều hơn một Quái thú). Ấn nút UPGRADE để tiêu hao Food nâng cấp Quái thú.
BasicFunctions.cpp: Gồm các hàm đơn giản như tạo màn hình, hiển thị ảnh, hiển thị chữ, kiểm tra va chạm của Quái thú.
Các chức năng đã cài được cho game:
Hiển thị bản đồ: hiển thị các thông số bản đồ chính, Gold và Food của người chơi, các nút chức năng.
Mở túi đồ: xem danh sách các Quái thú của người chơi, chọn Quái thú vào đội hình và nâng cấp Quái thú.
Chiêu mộ quái thú: Mua Quái thú mới về đội.
Thoát game, làm mới game, tiếp tục game.
Nguồn tham khảo:
Trò chơi Monster Saga: https://www.silvergames.com/vi/monster-saga
Hình ảnh Quái thú: https://craftpix.net/?srsltid=AfmBOorgsco13RJZlzpFa705Wo_oWbpMzc6le4pM9zvgHhW2V3lluF2B
Link Github game: https://github.com/DinhHuyHoang1711/MonstersWar
Video Demo game: 
https://drive.google.com/file/d/1jAemvt5d1RonD6CPmquaEHXmH22tTKI2/view?usp=drive_link


