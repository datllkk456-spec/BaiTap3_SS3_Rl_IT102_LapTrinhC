#include <stdio.h>

int main() {
    // Khai bao cac bien dau vao
    int tuoi, mac_phim, suat_chieu, loai_ghe, la_ngay_thuong, doi_tuong;
    
    // Khai bao cac bien tinh toan tien te (su dung kieu long de xu ly so lon)
    long gia_ve_goc = 0;
    long phu_thu_ghe = 0;
    long tien_giam = 0;
    long tong_tien = 0;
    int phan_tram_giam = 0;

    printf("=== HỆ THỐNG QUẢN LÝ BÁN VÉ CGV CINEMA ===\n");

    // --- YÊU CẦU 1: KIỂM TRA TUỔI ---
    printf("Nhập tuổi của khách hàng: ");
    scanf("%d", &tuoi);
    if (tuoi < 0 || tuoi > 120) {
        printf("Lỗi: Số tuổi nhập vào không hợp lệ!\n");
        return 1;
    }

    // --- YÊU CẦU 2: KIỂM SOÁT ĐỘ TUỔI THEO MÁC PHIM ---
    printf("Nhập mác phim (1: P, 2: T16, 3: T18): ");
    scanf("%d", &mac_phim);
    
    if (mac_phim == 2 && tuoi < 16) {
        printf("Từ chối bán vé: Phim T16 yêu cầu khán giả từ 16 tuổi trở lên!\n");
        return 1;
    } else if (mac_phim == 3 && tuoi < 18) {
        printf("Từ chối bán vé: Phim T18 cấm khán giả dưới 18 tuổi!\n");
        return 1;
    } else if (mac_phim != 1 && mac_phim != 2 && mac_phim != 3) {
        printf("Lỗi: Mã phân loại phim không hợp lệ!\n");
        return 1;
    }

    // --- YÊU CẦU 3: ĐỊNH GIÁ VÉ GỐC QUA SWITCH-CASE ---
    printf("Nhập suất chiếu (1: Sáng, 2: Chiều, 3: Tối): ");
    scanf("%d", &suat_chieu);
    
    switch (suat_chieu) {
        case 1:
            gia_ve_goc = 70000;
            break;
        case 2:
            gia_ve_goc = 90000;
            break;
        case 3:
            gia_ve_goc = 120000;
            break;
        default:
            printf("Lỗi: Lựa chọn suất chiếu không nằm trong menu!\n");
            return 1; // Ket thuc ngay neu chon sai menu
    }

    // --- YÊU CẦU 4: TÍNH PHỤ THU LOẠI GHẾ ---
    printf("Nhập loại ghế (1: Thường, 2: VIP, 3: Couple): ");
    scanf("%d", &loai_ghe);
    
    if (loai_ghe == 1) {
        phu_thu_ghe = 0;
    } else if (loai_ghe == 2) {
        phu_thu_ghe = 15000;
    } else if (loai_ghe == 3) {
        phu_thu_ghe = 30000;
    } else {
        printf("Lỗi: Loại ghế không hợp lệ!\n");
        return 1;
    }

    // --- NHẬP THÔNG TIN CHIẾT KHẤU ---
    printf("Có phải ngày thường không? (1: Có, 0: Không): ");
    scanf("%d", &la_ngay_thuong);

    printf("Nhập đối tượng (1: HSSV, 2: Người cao tuổi, 3: Thường): ");
    scanf("%d", &doi_tuong);

    // --- YÊU CẦU 5: TÍNH CHIẾT KHẤU NGÀY THƯỜNG ---
    if (la_ngay_thuong == 1) {
        // Toán tử logic || giúp gộp gọn 2 điều kiện cho người cao tuổi
        if (doi_tuong == 2 || tuoi >= 60) {
            phan_tram_giam = 30;
            tien_giam = gia_ve_goc * 0.30;
        } else if (doi_tuong == 1) {
            phan_tram_giam = 20;
            tien_giam = gia_ve_goc * 0.20;
        } else {
            tien_giam = 0;
        }
    } else {
        // Cuối tuần không áp dụng chiết khấu
        tien_giam = 0;
    }

    // --- YÊU CẦU 6: TỔNG KẾT TÀI CHÍNH ---
    tong_tien = (gia_ve_goc - tien_giam) + phu_thu_ghe;

    // --- TIẾN HÀNH IN HÓA ĐƠN THEO FORMAT ---
    // (Xử lý chuỗi tên để in ra bill cho đẹp)
    const char* ten_phim = (mac_phim == 1) ? "P" : (mac_phim == 2) ? "T16" : "T18";
    const char* ten_suat = (suat_chieu == 1) ? "Suất Sáng" : (suat_chieu == 2) ? "Suất Chiều" : "Suất Tối / Blockbuster";
    const char* ten_ghe = (loai_ghe == 1) ? "Ghế Thường" : (loai_ghe == 2) ? "Ghế VIP" : "Ghế Couple";

    printf("\n--------------------------------------------------\n");
    printf("              HÓA ĐƠN THANH TOÁN VÉ PHIM          \n");
    printf("--------------------------------------------------\n");
    printf("Khán giả : %d tuổi (Đủ điều kiện xem phim %s)\n", tuoi, ten_phim);
    printf("Suất chiếu : %s\n", ten_suat);
    printf("Loại ghế : %s\n", ten_ghe);
    printf("--------------------------------------------------\n");
    
    // Mẹo nhỏ: Dùng toán tử chia /1000 và lấy dư %1000 để in dấu phẩy (vd: 120,000)
    printf("Giá vé gốc : %ld,%03ld VNĐ\n", gia_ve_goc / 1000, gia_ve_goc % 1000);
    
    if (tien_giam > 0) {
        printf("Giảm giá (%d%%) : -%ld,%03ld VNĐ\n", phan_tram_giam, tien_giam / 1000, tien_giam % 1000);
    }
    
    if (phu_thu_ghe > 0) {
        printf("Phụ thu %s : +%ld,%03ld VNĐ\n", ten_ghe, phu_thu_ghe / 1000, phu_thu_ghe % 1000);
    }
    
    printf("--------------------------------------------------\n");
    printf("TỔNG TIỀN THANH TOÁN: %ld,%03ld VNĐ\n", tong_tien / 1000, tong_tien % 1000);
    printf("--------------------------------------------------\n");

    return 0; // Chương trình kết thúc thành công
}