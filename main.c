#include <stdio.h>

int main() {
    int tuoi;
    int mac_phim;
    int suat_chieu;
    int loai_ghe;
    int la_ngay_thuong;
    int doi_tuong;

    float gia_ve_goc = 0;
    float phu_thu_ghe = 0;
    float tien_giam = 0;
    float tong_tien;

    printf("=== HE THONG QUAN LY BAN VE CGV CINEMA ===\n");

    // Nhap thong tin
    printf("Nhap tuoi cua khach hang: ");
    scanf("%d", &tuoi);

    // Kiem tra tuoi
    if (tuoi < 0 || tuoi > 120) {
        printf("Loi: So tuoi nhap vao khong hop le!\n");
        return 0;
    }

    printf("Nhap mac phim (1: P, 2: T16, 3: T18): ");
    scanf("%d", &mac_phim);

    // Kiem tra ma phim va dieu kien tuoi
    if (mac_phim == 1) {
        // Phim P: moi do tuoi deu duoc xem
    } 
    else if (mac_phim == 2) {
        if (tuoi < 16) {
            printf("Tu choi ban ve: Phim T16 yeu cau khan gia tu 16 tuoi tro len!\n");
            return 0;
        }
    } 
    else if (mac_phim == 3) {
        if (tuoi < 18) {
            printf("Tu choi ban ve: Phim T18 cam khan gia duoi 18 tuoi!\n");
            return 0;
        }
    } 
    else {
        printf("Loi: Ma phan loai phim khong hop le!\n");
        return 0;
    }

    printf("Nhap suat chieu (1: Sang, 2: Chieu, 3: Toi): ");
    scanf("%d", &suat_chieu);

    // Tinh gia ve theo suat chieu
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
            printf("Loi: Lua chon suat chieu khong nam trong menu!\n");
            return 0;
    }

    printf("Nhap loai ghe (1: Thuong, 2: VIP, 3: Couple): ");
    scanf("%d", &loai_ghe);

    // Tinh phu thu ghe
    switch (loai_ghe) {
        case 1:
            phu_thu_ghe = 0;
            break;

        case 2:
            phu_thu_ghe = 15000;
            break;

        case 3:
            phu_thu_ghe = 30000;
            break;

        default:
            printf("Loi: Loai ghe khong hop le!\n");
            return 0;
    }

    printf("Co phai ngay thuong khong? (1: Co, 0: Khong): ");
    scanf("%d", &la_ngay_thuong);

    // Kiem tra ngay thuong
    if (la_ngay_thuong != 0 && la_ngay_thuong != 1) {
        printf("Loi: Du lieu ngay thuong khong hop le!\n");
        return 0;
    }

    printf("Nhap doi tuong (1: HSSV, 2: Nguoi cao tuoi, 3: Thuong): ");
    scanf("%d", &doi_tuong);

    // Kiem tra doi tuong
    if (doi_tuong != 1 && doi_tuong != 2 && doi_tuong != 3) {
        printf("Loi: Doi tuong khong hop le!\n");
        return 0;
    }

    // Tinh giam gia
    if (la_ngay_thuong == 1) {
        if (doi_tuong == 1) {
            // HSSV giam 20%
            tien_giam = gia_ve_goc * 0.20;
        } 
        else if (doi_tuong == 2 || tuoi >= 60) {
            // Nguoi cao tuoi giam 30%
            tien_giam = gia_ve_goc * 0.30;
        } 
        else {
            tien_giam = 0;
        }
    } 
    else {
        // Cuoi tuan khong giam
        tien_giam = 0;
    }

    // Tinh tong tien
    tong_tien = (gia_ve_goc - tien_giam) + phu_thu_ghe;

    // In hoa don
    printf("\n--------------------------------------------------\n");
    printf("              HOA DON THANH TOAN VE PHIM\n");
    printf("--------------------------------------------------\n");

    printf("Khan gia : %d tuoi", tuoi);

    if (mac_phim == 1) {
        printf(" (Du dieu kien xem phim P)\n");
    } 
    else if (mac_phim == 2) {
        printf(" (Du dieu kien xem phim T16)\n");
    } 
    else {
        printf(" (Du dieu kien xem phim T18)\n");
    }

    // Hien thi suat chieu
    printf("Suat chieu : ");
    switch (suat_chieu) {
        case 1:
            printf("Suat Sang\n");
            break;

        case 2:
            printf("Suat Chieu\n");
            break;

        case 3:
            printf("Suat Toi / Blockbuster\n");
            break;
    }

    // Hien thi loai ghe
    printf("Loai ghe : ");
    switch (loai_ghe) {
        case 1:
            printf("Ghe Thuong\n");
            break;

        case 2:
            printf("Ghe VIP\n");
            break;

        case 3:
            printf("Ghe Couple\n");
            break;
    }

    printf("--------------------------------------------------\n");
    printf("Gia ve goc : %.0f VNĐ\n", gia_ve_goc);

    if (doi_tuong == 1 && la_ngay_thuong == 1) {
        printf("Giam gia (20%%) : -%.0f VNĐ\n", tien_giam);
    } 
    else if ((doi_tuong == 2 || tuoi >= 60) && la_ngay_thuong == 1) {
        printf("Giam gia (30%%) : -%.0f VNĐ\n", tien_giam);
    } 
    else {
        printf("Giam gia : -0 VNĐ\n");
    }

    if (loai_ghe == 1) {
        printf("Phu thu ghe Thuong : +%.0f VNĐ\n", phu_thu_ghe);
    } 
    else if (loai_ghe == 2) {
        printf("Phu thu ghe VIP : +%.0f VNĐ\n", phu_thu_ghe);
    } 
    else {
        printf("Phu thu ghe Couple : +%.0f VNĐ\n", phu_thu_ghe);
    }

    printf("--------------------------------------------------\n");
    printf("TONG TIEN THANH TOAN: %.0f VNĐ\n", tong_tien);
    printf("--------------------------------------------------\n");

    return 0;
}
